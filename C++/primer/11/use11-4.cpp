#include <iostream>
#include "11-4.h"
using namespace std;
int main()
{
	MYCTIME::CTime a;
	MYCTIME::CTime b(2,30);
	MYCTIME::CTime c;
	a.reset(3,4);
	cout<<"Time a:"<<a<<endl;
	cout<<"Time b:"<<b<<endl;
	c=a+b;
	cout<<"Time a+b:"<<c<<endl;
	cout<<"Time a-b:"<<(a-b)<<endl;
	cout<<"Time a*2:"<<a*2<<endl;
	cout<<"Time 3*a:"<<3*a<<endl;
	cout<<"Time b/2:"<<b/2<<endl;
}