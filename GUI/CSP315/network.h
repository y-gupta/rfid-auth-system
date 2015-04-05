#ifndef NETWORKTHREAD_H
#define NETWORKTHREAD_H
#include "thread.h"
#include "request.h"
#include "user.h"
#include <string>
#include <stdint.h>
#include <curl/curl.h>
using namespace std;

class NetworkJob : public ThreadedJob{
public:
    string url;
    uint16_t type;
    static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp);
    int process();
};

class Network{
public:
    static string url;
    static WorkerThread *thread;
    Network();
    static void init(string _url);

    static void sendRequest(Request *r);
};

#endif // NETWORKTHREAD_H
