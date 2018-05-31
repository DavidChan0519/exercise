#include <iostream>
using namespace std;

int main()
{
	int i;
	double j;

	int& a = i;
	double& b= j;

	i = 3;
	cout <<"i"<<i<<endl;
	cout<<"i reference"<<a<<endl;

	j = 1.2;
	cout<<"j"<<endl;
	cout<<"j reference"<<b<<endl;
	return 0;
}
