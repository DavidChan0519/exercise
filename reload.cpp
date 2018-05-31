#include <iostream>
using namespace std;

class A
{
public:
	void print(int a);
	void print(char* b);
	void print(double c);
};

void A::print(int a)
{
	cout << "print int "<< a<< endl;

}

void A::print(char *b)
{

	cout << "print string " << b <<endl;
}

void A::print(double c)
{

	cout << "print double " << c <<endl;
}

int main()
{
	A test;
	
	test.print(1);
	test.print((char *)"1.00 hellow");
	test.print(1.00000);
	return 0;
}
