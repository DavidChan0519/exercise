#include <iostream>
#include <thread>
#include <atomic>

using namespace std;

std::atomic<long long> data;
long long val=0;
void do_work()
{
    data.fetch_add(1, std::memory_order_relaxed);
    cout << "data:"<< data.load() << endl;
}

void del_work()
{
    val++;
    cout <<  "val:" << val << endl;
}



int main()
{
    std::thread th1(do_work);
    std::thread th2(do_work);
    std::thread th3(do_work);
    std::thread th4(do_work);
    std::thread th5(do_work);

    std::thread th11(del_work);
    std::thread th12(del_work);
    std::thread th13(del_work);
    std::thread th14(del_work);
    std::thread th15(del_work);

    th1.join();
    th2.join();
    th3.join();
    th4.join();
    th5.join();

    th11.join();
    th12.join();
    th13.join();
    th14.join();
    th15.join();

    std::cout << "Result 1:" << data << '\n';
    std::cout << "Result 2:" << val << '\n';
}
