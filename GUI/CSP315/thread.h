#pragma once
#include <utility>
#include <deque>
#include <pthread.h>
#include <cassert>
#include <iostream>

using namespace std;

#define JOB_EXIT 0
using namespace std;
class ThreadedEntity{
    pthread_mutex_t mutex;
public:
    ThreadedEntity(){
        pthread_mutex_init(&mutex,NULL);
    }
    ~ThreadedEntity(){
        pthread_mutex_destroy(&mutex);
    }
    void lock(){
        pthread_mutex_lock(&mutex);
    }
    void unlock(){
        pthread_mutex_unlock(&mutex);
    }
};
class ThreadedJob{
public:
  int cost;
  ThreadedJob(int _cost=1){
    cost=_cost;
  }
  virtual ~ThreadedJob(){}
  virtual int process(){//Non zero return value terminates thread!
    delete this;
    return 1;
  }
};

class WorkerThread{
   pthread_t thread;
    pthread_mutex_t queue_m;
    pthread_cond_t queue_cv;
    pthread_attr_t thread_attr;
    deque<ThreadedJob*> jobs;
    int load;
    bool destruct_on_exit;
    void loop(){
    ThreadedJob *j;bool run=true;int cost,err;
        while(run){
            pthread_mutex_lock(&queue_m);
            while(jobs.empty()){
                pthread_cond_wait(&queue_cv,&queue_m);
            }
            j=jobs.front();
            jobs.pop_front();
        assert(j&&"Valid job");
            pthread_mutex_unlock(&queue_m);
        cost=j->cost;
        err = j->process();
        run=(err==0);
        load-=cost;
        }
        pthread_exit(NULL);
        if(destruct_on_exit){
            delete this;
        }
    }
public:
    void pushJob(ThreadedJob *j){
        assert(j && "Valid job");
        load+=j->cost;
        pthread_mutex_lock(&queue_m);
        jobs.push_back(j);
        pthread_cond_signal(&queue_cv);
        pthread_mutex_unlock(&queue_m);
    }
    int getLoad(){
        return load;
    }
    int start(bool _destruct_on_exit=false){
        destruct_on_exit=_destruct_on_exit;
        pthread_cond_init(&queue_cv,NULL);
        pthread_mutex_init(&queue_m,NULL);
        pthread_attr_init(&thread_attr);
        pthread_attr_setdetachstate(&thread_attr, PTHREAD_CREATE_JOINABLE);
        int res= pthread_create(&thread,&thread_attr,threadEntry,this);
        return res;
    }
    WorkerThread(){
        destruct_on_exit=false;
        load=0;
    }
    ~WorkerThread(){
        pushJob(new ThreadedJob());
        pthread_join(thread,NULL);
        //wait for finishing
        pthread_attr_destroy(&thread_attr);
        pthread_cond_destroy(&queue_cv);
        pthread_mutex_destroy(&queue_m);
    }
    static void* threadEntry(void *payload){
        ((WorkerThread*)payload)->loop();
        return 0;
    }

};
