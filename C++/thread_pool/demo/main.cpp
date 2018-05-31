#include <iostream>
#include "My_task_queue.h"
#include "My_thread_pool.h"
#include <stdio.h>

typedef boost::function<void(void)> my_task;
 
void print_task(int i)
{
    printf("I'm task %d\n",i);
}
 
int main(int argc, char* argv[])
{
    My_thread_pool tp(10);
    tp.init();
     
    my_task t[4];
    for (int i= 0; i<4;++i)
    {
        t[i]=boost::bind(print_task,i+1);
        tp.post(t[i]);
    }
    
    tp.wait();
    return 0;
}
