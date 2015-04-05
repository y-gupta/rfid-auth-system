#ifndef NETWORKTHREAD_H
#define NETWORKTHREAD_H
#include "thread.h"
#include "request.h"
#include "user.h"
#include <string>
#include <stdint.h>
using namespace std;

class NetworkJob : public ThreadedJob{
public:
    string url;
    uint16_t type;
    static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
    {
        ((std::string*)userp)->append((char*)contents, size * nmemb);
        return size * nmemb;
    }
    virtual int process(){
        CURL *curl = curl_easy_init();
        CURLcode res;
        string readBuffer;
        if(curl){
         curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
         curl_easy_setopt(curl, CURLOPT_URL, url);
         curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
         curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
         res = curl_easy_perform(curl);
         if(res != CURLE_OK){
             fprintf(stderr, "curl_easy_perform() failed: %s\n",curl_easy_strerror(res));
             return 1;
         }
             curl_easy_cleanup(curl);
             processResponse(readBuffer,type);
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
    static void init(string _url){
        url = _url;
        thread = new WorkerThread();
        thread->start();
    }

    static void sendRequest(Request *r){
        assert(thread && "valid worker thread");
        assert(r && "valid request");
        string query = r->toString();
        string qurl =  url+query;
        NetWorkJob job;
        job.url = qurl;
        job.type = r->type;
        thread->pushJob(job);
    }
};

#endif // NETWORKTHREAD_H
