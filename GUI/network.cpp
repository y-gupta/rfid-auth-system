#include "network.h"
#include "mainwindow.h"
void processResponse(string resp,uint16_t type){
    //parse the json string
    //{key1:value1,key2:value2}

    switch(type){
    case AUTH:
        User usr;
        if(true){   // TODO: use the success in the parsed string
            usr.init(1,"Shubham Rawat","2013CS10258","Zanskar");
        }
        MainWindow::processAuthResponse(usr);
        break;
    }

}

 size_t NetWorkJob::WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}
int NetWorkJob::process(){
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
Network::Network(){
    url = "";
    thread = 0;
}
void Network::init(string _url){
    url = _url;
    thread = new WorkerThread();
    thread->start();
}

void Network::sendRequest(Request *r){
    assert(thread && "valid worker thread");
    assert(r && "valid request");
    string query = r->toString();
    string qurl =  url+query;
    NetWorkJob job;
    job.url = qurl;
    job.type = r->type;
    thread->pushJob(job);
}

