#include "network.h"
#include "mainwindow.h"

string Network::url = "";
WorkerThread* Network::thread=NULL;
Response Network::response;
void setResponse(string resp,uint16_t type){
    Network::response.lock();
    Network::response.set(resp,type);
    Network::response.unlock();
}
NetworkJob::~NetworkJob(){}
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
     cout<<url<<endl;
     curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
     curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
     curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
     curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
     res = curl_easy_perform(curl);

     if(res != CURLE_OK){

         fprintf(stderr, "curl_easy_perform() failed: %s\n",curl_easy_strerror(res));
         delete this;
         return 1;
     }
         curl_easy_cleanup(curl);
         setResponse(readBuffer,type);
         delete this;
         return 0;
    }
    delete this;
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
    cout<<"Sending request:Type = "<<r->type<<endl;

    Network::thread->pushJob(job);
}

