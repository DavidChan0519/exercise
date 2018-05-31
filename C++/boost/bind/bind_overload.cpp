#include <iostream>
#include <boost/thread.hpp>
#include <boost/noncopyable.hpp>
#include <boost/function.hpp>

using namespace std;

class Test
{
public:
	int a;
//private:
	//oost::mutex dl_mutex;
};


class Class
        {
        public:
		Class(int num=50) {
			testobj.a = num;
		}
	
		void test()
		{
			//typedef void (Class::*OverloadFuncType)(float);
			//boost::function<void(float)> floatFunction;
			//floatFunction = boost::bind(static_cast<OverloadFuncType>(&Class::overload), this ,_1);
			//boost::thread ins(floatFunction , 1.2);
			//ins.join();

			typedef void (Class::*OverloadFuncType)(Test &);

			boost::function<void(Test &)> floatFunction;

			floatFunction = boost::bind(static_cast<OverloadFuncType>(&Class::overload), this ,_1);
			
			boost::thread *pthread = new boost::thread(floatFunction ,testobj );
			pthread->join();
		}

                void overload(float param){
			cout << "==== value: ===" << param <<endl;
			
		}
                void overload(int param){}
		void overload(Test &param){
			cout << "==== mem value: ===" << param.a <<endl;
		}
	private:
		Test testobj;
        };


int main()
{

	Class instance1(256);
	instance1.test();
	
        Class instance2;
	instance2.test();
	
	//typedef void (Class::*OverloadFuncType)(float);
	//boost::bind(static_cast<OverloadFuncType>(&Class::overload), &instance,_1);
	return 0;
}
