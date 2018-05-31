#include <iostream>
using namespace std;

int main()
{
	cout<<"输入两个整数（先输入较小的数，再输入较大的数）：";
	int a,b,sum=0;
	cin>>a;
	cin.clear();
	cin>>b;
	for(int i=a;i<=b;i++)
		sum +=i;
	cout<<a<<"到"<<b<<"之间的数的合是："<<sum<<endl;
	return 0;
}
