#ifndef NETWORKTHREAD_H
#define NETWORKTHREAD_H
#include "thread.h"

class NetworkJob : public ThreadedJob{
public:
    string url;
    virtual int process(){
        CURL *curl = curl_easy_init();
        CURLcode res;

        if(curl){
         curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
         curl_easy_setopt(curl, CURLOPT_URL, url);
         res = curl_easy_perform(curl);
         if(res != CURLE_OK){
             fprintf(stderr, "curl_easy_perform() failed: %s\n",curl_easy_strerror(res));
             return 1;
         }
             curl_easy_cleanup(curl);
             return 0;
        }
        return 2;
    }
};

class Network{
    string url;
    WorkerThread *thread;

public:
    NetWork(){
        url = "";
        thread = 0;
    }
    void init(string _url){
        url = _url;
        thread = new WorkerThread();
        thread->start();
    }

    int sendRequest(Request *r){
        assert(thread && "valid worker thread");
        assert(r && "valid request");
        string query = r->toString();
    }
};

#endif // NETWORKTHREAD_H
