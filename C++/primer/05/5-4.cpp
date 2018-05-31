#include <iostream>
#include <string>
using namespace std;

int main()
{
	
	int count[12],sum=0;
	string month[12]={"一月","二月","三月","四月",
							"五月","六月","七月","八月",
							"九月","十月","十一月","十二月"
							};
	for(int i=0;i<12;i++)
	{
		cout<<"输入"<<month[i]<<"的销售数量：";
		cin>>count[i];
		sum+=count[i];
	}
	cout<<"十二个月的总销售数量是:"<<sum<<endl;
	//double a=100,sum1=0,b=100,sum2=0;
	//int count=0;
	//while((sum1+=a*0.1) >= (sum2+=(sum2+b)*0.05))
	//{
	//	count++;
	//}
	//cout<<count<<"年后，Cleo的投资超过Daphne的投资。"<<endl;
	return 0;
}