#include <iostream>
#include <thread>
#include <vector>
#include <algorithm>

using namespace std;

void do_work(const int i)
{
	
	cout << i << " id: "<< this_thread::get_id() <<" do work"<<endl;
}

int main()
{
	thread test;
	cout << "id :" << test.get_id() << endl;
	vector<thread> thread_vec;
	unsigned long thread_max = thread::hardware_concurrency();
	cout << "max num:"<< thread_max << endl;
	
	thread_vec.push_back(thread(do_work,1));
	thread_vec.push_back(thread(do_work,2));
	thread_vec.push_back(thread(do_work,3));
	
	for_each(thread_vec.begin(), thread_vec.end(), mem_fn(&std::thread::join));
	return 0;
}
