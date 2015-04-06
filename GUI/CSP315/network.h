#ifndef NETWORKTHREAD_H
#define NETWORKTHREAD_H
#include "thread.h"
#include "request.h"
#include "mainwindow.h"
#include "user.h"
#include "response.h"
#include <string>
#include <stdint.h>
#include <curl/curl.h>
using namespace std;

class NetworkJob : public ThreadedJob{
public:
    string url;
    uint16_t type;
    static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp);
    virtual int process();
};
class Network{
public:
    static Response response;
    static string url;
    static WorkerThread *thread;
    Network();
    static void init(string _url);
    static void sendRequest(Request *r);
};

#endif // NETWORKTHREAD_H
