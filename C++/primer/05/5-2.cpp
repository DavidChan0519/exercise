#include <iostream>
using namespace std;

int main()
{
	cout<<"������һ����(0 �˳�)��";
	double a,sum=0;
	//cin>>a;
	//cout.precision(4);
	//cout.setf(std::ios_base::boolalpha);
	while(cin>>a&&a!=0)
	{
		sum+=a;
		cout<<"��Ŀǰ�ĺ���:"<<sum<<endl;
		cout<<"������һ����(0 �˳�)��";
		//cin>>a;
	}
	
	return 0;
}
