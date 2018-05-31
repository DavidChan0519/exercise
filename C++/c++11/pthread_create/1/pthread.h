#ifndef THREAD_H_
#define THREAD_H_

#include <boost/noncopyable.hpp>
#include <functional>
#include <pthread.h>
#include <functional>


class Thread : boost::noncopyable
{
public:
    typedef std::function<void ()> ThreadCallback;

    Thread(ThreadCallback callback);
    ~Thread();

    void start();
    void join();

    static void *runInThread(void *);

private:
    pthread_t threadId_;
    bool isRunning_;
    ThreadCallback callback_; //回调函数
};


Thread::Thread(ThreadCallback callback)
: threadId_(0),
  isRunning_(false),
  callback_(std::move(callback))
{

}
    
Thread::~Thread()
{
    if(isRunning_)
    {
        //detach
        pthread_detach(threadId_);
    }
}

void Thread::start()
{
    pthread_create(&threadId_, NULL, runInThread, this);
    isRunning_ = true;
}
void Thread::join()
{
    pthread_join(threadId_, NULL);
    isRunning_ = false;
}

void *Thread::runInThread(void *arg)
{
    Thread *pt = static_cast<Thread*>(arg);
    pt->callback_(); //调用回调函数

    return NULL;
}

#endif //THREAD_H_
