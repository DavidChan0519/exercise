#ifndef MY_TASK_QUEUE
#define MY_TASK_QUEUE
 
#include <queue>
#include <boost/thread.hpp>
#include <boost/noncopyable.hpp>
#include <boost/function.hpp>
 
//定义任务
typedef boost::function<void(void)> my_task;
 
class Task_queue:boost::noncopyable
{
public:
    void push_task(const my_task & task_func)
    {
        boost::unique_lock<boost::mutex> lock(my_mutex);
        my_queue.push(task_func);
        cond.notify_one();          
    }

    my_task get_task()
    {
        boost::unique_lock<boost::mutex> lock(my_mutex);
        if(my_queue.size()==0)
        {
            cond.wait(lock);
        }
        my_task task(my_queue.front());
        my_queue.pop();
        return task;
    }

    int get_size()
    {
        return my_queue.size();
    }

private:
    std::queue<my_task> my_queue;
    boost::condition_variable_any cond;
    boost::mutex my_mutex;
};
 
#endif
