#include <iostream>
using namespace std;

class hello
{
public:
	int a;
	int b;
	void print();
	hello();
	~hello();
};

hello::hello()
{
	cout<<"construct func"<<endl;
}

hello::~hello()
{
	cout<<"descontruction func"<<endl;
}


void hello::print()
{
	cout << "hello world" << endl;
	return ;
}

int main()
{
	hello classA;
	classA.a = 1;
	classA.b = 2;

	classA.print();
	cout << "a:" << classA.a << endl;
	cout << "b:" << classA.b << endl;
	return 0;
}
