#include <iostream>
using namespace std;

int main()
{
	cout<<"请输入一个数(0 退出)：";
	double a,sum=0;
	//cin>>a;
	//cout.precision(4);
	//cout.setf(std::ios_base::boolalpha);
	while(cin>>a&&a!=0)
	{
		sum+=a;
		cout<<"到目前的合是:"<<sum<<endl;
		cout<<"请输入一个数(0 退出)：";
		//cin>>a;
	}
	
	return 0;
}
