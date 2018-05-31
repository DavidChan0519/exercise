#include <mutex>
#include <thread>
#include <chrono>
#include <iostream>

using namespace std;
 
struct Box {
    explicit Box(int num) : num_things{num} {}
 
    int num_things;
    std::mutex m;
};
 
void transfer(Box &from, Box &to, int num)
{
    // don't actually take the locks yet
    std::unique_lock<std::mutex> lock1(from.m, std::defer_lock);
    std::unique_lock<std::mutex> lock2(to.m, std::defer_lock);
 
    // lock both unique_locks without deadlock
    std::lock(lock1, lock2);
    cout << "org val of acc1.num:" << from.num_things << endl;
    from.num_things -= num;
    cout << "org val of acc2.num:" << to.num_things << endl;
    to.num_things += num;
	 
    // 'from.m' and 'to.m' mutexes unlocked in 'unique_lock' dtors
}
 
int main()
{
    Box acc1(100);
    Box acc2(50);
 
    std::thread t1(transfer, std::ref(acc1), std::ref(acc2), 10);
    std::thread t2(transfer, std::ref(acc2), std::ref(acc1), 5);
 
    t1.join();
    t2.join();

    cout << "later val of acc1.num:" << acc1.num_things << endl;
    cout << "later val of acc2.num:" << acc2.num_things << endl;
}
