#include <iostream>
using namespace std;

int main()
{
	double a=100,sum1=0,b=100,sum2=0;
	int count=0;
	while((sum1+=a*0.1) >= (sum2+=(sum2+b)*0.05))
	{
		count++;
	}
	cout<<count<<"���Cleo��Ͷ�ʳ���Daphne��Ͷ�ʡ�"<<endl;
	return 0;
}