#include <iostream>
#include <thread>
using namespace std;

void hello()
{
	cout << "hello world"<<endl;
}

struct func
{
	int&	i;
public:
	explicit func(int& i_) :	i(i_){}
	void	operator()()
	{
		for(unsigned j=0;j<10;++j)
		{
			cout << "index:"<<j<<"- "<<i << endl;
		}
	}
};


void ref_test(int& m)
{
	cout << "input :" << m << endl;
	m++;
}

int main()
{
	thread t(hello);
	t.join();

	int temp=100;
	thread p(ref_test,ref(temp));
	p.join();
	cout << "after:"<<temp<<endl;
	
	
	int i= 128;	
	func ins(i);
	
	//func j=i;//convert implicitly
	//j();

	thread m{ins};
	thread n(ins);
	thread k{func(i)};
	
	m.join();
	n.join();
	k.join();
	
	return 0;
}
