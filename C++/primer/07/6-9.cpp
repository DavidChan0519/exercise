#include <iostream>
using namespace std;

double calculate(const double n,const double m,double (*fp)(double,double))
{
	double sum;
	sum=fp(n,m);
	cout<<"answer="<<sum<<endl;
	return sum;
}
double add(double x,double y)
{
	return x+y;
}
double div(double x,double y)
{
	if(y!=0)
		return x/y;
	return 0;
}
int main()
{
	double n,m;
	cout<<"Enter two number(q to quit):";
	while(cin>>n>>m)
	{
		calculate(n,m,add);
		calculate(n,m,div);
		cout<<"Enter two number (q to quit):";
	}
	return 0;
}