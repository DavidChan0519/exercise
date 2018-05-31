#include <iostream>
#include <mutex>
#include <thread>
#include <chrono>

using namespace std;

int g_var=0;
mutex g_lock;

void add()
{
	lock_guard<mutex> lock(g_lock); 
	g_var ++;
	this_thread::sleep_for(chrono::seconds(2));
	cout << "thread id: " << this_thread::get_id() <<" var:" << g_var << endl;
	
}


int main()
{
	thread test1(add);
	thread test2(add);
	thread test3(add);
	test1.join();
	test2.join();
	test3.join();
	return 0;
}
