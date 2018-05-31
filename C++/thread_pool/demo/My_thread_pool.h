//*************************************************************************
//Copyright: 
//Author:     Sail
//Filename:    
//Last Mod time: My_thread_pool
//*************************************************************************
//Remarks:
//线程池使用boost中的thread_group来管理和创建工作线程，使其阻塞在任队列中
//
//*************************************************************************
 
#ifndef MY_THREAD_POOL
#define MY_THREAD_POOL
 
#include <boost/thread.hpp>
#include <boost/noncopyable.hpp>
#include <boost/function.hpp>
#include <iostream>
 
#include "My_task_queue.h"
using namespace std;
 
typedef boost::function<void(void)> my_task;
 
class My_thread_pool:boost::noncopyable
{
public:
    My_thread_pool(int num):thread_num(num),is_run(false){}
    ~My_thread_pool(){}
    void init()
    {
        is_run=true;
        if(thread_num<=0)
            return;
        for(int i=0;i<thread_num;++i)
        {
	    cout << "create thread: " << i << endl;
            my_thread_group.add_thread(new boost::thread(boost::bind(&My_thread_pool::run,this)));
        }   
    }
 
    void stop()
    {
        is_run=false;
    }
 
    void  post(const my_task & task)
    {
        my_queue.push_task(task);
    }
 
    void wait()
    {
        my_thread_group.join_all();
    }
     
private:
    Task_queue my_queue;
    boost::thread_group my_thread_group;
    int thread_num;
    volatile bool is_run;
    void run()
    {
        while(is_run)
        {
	    cout << "processing task..."<<endl; 
            my_task task=my_queue.get_task();
            task();
        }
    }
};
 
#endif
