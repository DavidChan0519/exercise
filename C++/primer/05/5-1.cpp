#include <iostream>
using namespace std;

int main()
{
	cout<<"���������������������С������������ϴ��������";
	int a,b,sum=0;
	cin>>a;
	cin.clear();
	cin>>b;
	for(int i=a;i<=b;i++)
		sum +=i;
	cout<<a<<"��"<<b<<"֮������ĺ��ǣ�"<<sum<<endl;
	return 0;
}
