#include <iostream>
using namespace std;

double *input(double *value,int n)
{
	value=new double[n+1];
	cout<<"输入成绩："<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>value[i];
	}
	return value;
}

double Compute(double *value,int n)
{
	double sum=0;double ave=0;
	for(int i=0;i<n;i++)
	{
		sum +=*value;
		value++;
	}
	return ave=sum/n;
}
void Show(double ave)
{
	cout<<"平均值:"<<ave<<endl;
}
int main()
{
	double *a=NULL;
	int n=0;
	cout<<"请输入要计算的成绩个数："<<endl;
	cin>>n;
	a=input(a,n);
	Show(Compute(a,n));
	if(a!=NULL)
	{
		delete [] a;a=NULL;
	}
	return 0;
}
		