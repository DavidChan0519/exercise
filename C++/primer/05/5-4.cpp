#include <iostream>
#include <string>
using namespace std;

int main()
{
	
	int count[12],sum=0;
	string month[12]={"һ��","����","����","����",
							"����","����","����","����",
							"����","ʮ��","ʮһ��","ʮ����"
							};
	for(int i=0;i<12;i++)
	{
		cout<<"����"<<month[i]<<"������������";
		cin>>count[i];
		sum+=count[i];
	}
	cout<<"ʮ�����µ�������������:"<<sum<<endl;
	//double a=100,sum1=0,b=100,sum2=0;
	//int count=0;
	//while((sum1+=a*0.1) >= (sum2+=(sum2+b)*0.05))
	//{
	//	count++;
	//}
	//cout<<count<<"���Cleo��Ͷ�ʳ���Daphne��Ͷ�ʡ�"<<endl;
	return 0;
}