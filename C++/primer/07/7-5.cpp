#include <iostream>

long double factorial(long double n)
{
	long double fact=0;
	if(n==0 || n==1)
		fact=1;
	else
		fact=factorial(n-1)*n;
	return fact;
}
int main()
{
	using std::cout;
	using std::cin;
	using std::endl;

	long double n;
	cout<<"输入所求阶乘的数(q to quit)："<<endl;
	while(cin>>n && n!='q')
	{
		cout<<n<<"的阶乘："<<factorial(n)<<endl;
		cout<<"输入所求阶乘的数(q to quit)："<<endl;
	}
	return 0;
}
		