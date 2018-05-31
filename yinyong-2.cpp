#include <iostream>
using namespace std;

int g_value = 21;


int & setvalue(int a)
{
	
	g_value = a;
	return g_value;
}

int main()
{
	cout << "before set:"<<g_value<<endl;
	setvalue(100) = 200;
	cout << "after set:"<<g_value<<endl;
	return 0;
}
