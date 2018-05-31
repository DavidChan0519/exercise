#include <iostream>
#include <cstring>
using namespace std;


class Print
{
public:
	void print_data(int a)const;
	void print_data(string b)const;
	void print_data(double c)const;
	void print_data(const string & d, int e)const;
};


void Print::print_data(int a)const
{
	cout << "int :"<< a <<endl;
}

void Print::print_data(string b)const
{
	cout << "string :" << b << endl;
}


void Print::print_data(double c)const
{
	cout << "double :" << c << endl;
}


void Print::print_data(const string &d, int e)const
{

	cout << "string & "<< d << "int " << e << endl;
}


int main()
{
	Print m;
	
	m.print_data(2);
	m.print_data("hello");
	m.print_data(1.11);
	m.print_data("world", 888);
	
	return 0;
}
