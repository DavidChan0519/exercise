#include <iostream>
#include <ctype.h>
#include <string>
using namespace std;

int main()
{
	int donation[10],sum=0;
	double ave=0;
	int count=0,n=0;
	//string str[2];
	cout<<"�������ʮ��doubleֵ(��������ֽ���):\n";
	while(count<10&&cin>>donation[count]) 
	{
		sum+=donation[count];
		count++;
		ave=sum/count;
	}
	for(int i=0;i<count;i++)
	{
		if(donation[i]>ave)
			n++;
	}
	cout<<"ƽ��ֵ:"<<ave<<"\n����ƽ��ֵ������ "<<n<<" ����"<<endl;
	return 0;
}