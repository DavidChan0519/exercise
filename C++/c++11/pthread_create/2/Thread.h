#ifndef THREAD_H_
#define THREAD_H_

#include <assert.h>
#include <unistd.h>
#include "NonCopyable.h"
#include <pthread.h>

class Thread :public noncopyable 
{
public:
    Thread();
    virtual ~Thread();

    void start();
    void join();

    virtual void run() = 0;

    pthread_t getThreadId() const
    { 
	return threadId_; 
    }

private:
    //提供给pthread_create的第三个参数使用
    static void *runInThread(void *arg);
    
    pthread_t threadId_;
    //pid_t tid_; //进程标示
    bool isRunning_;
};

Thread::Thread()
    :threadId_(0),
     isRunning_(false)
{

}

Thread::~Thread()
{
    if(isRunning_)
    {
        pthread_detach(threadId_);
    }
}

//static
void *Thread::runInThread(void *arg)
{
    Thread *pt = static_cast<Thread*>(arg);
    //pt->tid_ = syscall(SYS_gettid);
    pt->run();
    return NULL;
}

void Thread::start()
{
    pthread_create(&threadId_, NULL, Thread::runInThread, this);
    isRunning_ = true;
}

void Thread::join()
{
    assert(isRunning_);
    pthread_join(threadId_, NULL);
    isRunning_ = false;
}

#endif //THREAD_H_
