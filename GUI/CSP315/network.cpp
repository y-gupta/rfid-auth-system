#include "network.h"
#include "mainwindow.h"

string Network::url = "";
WorkerThread* Network::thread=NULL;
MainWindow* Network::w = NULL;

void processResponse(string resp,uint16_t type){
    //parse the json string
    //{key1:value1,key2:value2}

    switch(type){
    case AUTH:
        User usr;
        if(true){   // TODO: use the success in the parsed string
            usr.init(1,"Shubham Rawat","2013CS10258",resp);
        }
        Network::w->processAuthResponse(usr);
        break;
    }

}
size_t NetworkJob::WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}
int NetworkJob::process(){
    CURL *curl = curl_easy_init();
    CURLcode res;
    string readBuffer;
    if(curl){


     curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
     curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
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
    Network::url = "";
    Network::thread = 0;
}
void Network::init(string _url){
    Network::url = _url;
    Network::thread = new WorkerThread();
    Network::thread->start();
}

void Network::sendRequest(Request *r){
    assert(Network::thread && "valid worker thread");
    assert(r && "valid request");
    string query = r->toString();
    string qurl =  Network::url+query;
    NetworkJob *job = new NetworkJob;
    job->url = qurl;
    job->type = r->type;
    cout<<"Pusing the job"<<endl;
    Network::thread->pushJob(job);
}

