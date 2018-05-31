#include <iostream>
using namespace std;

template <typename T>

T maxn(T p[],int n=0)
{
	T temp;
	for(int i=0;i<n;i++)
	{
		if(p[0]<p[i])
		{
			temp=p[i];
			p[0]=p[i];
			p[i]=temp;
		}
	}
	return p[0];
}
template <> char * maxn<char *> (char *ps[],int n)
{
	size_t si1,si2;
	for(int i=0;i<n;i++)
	{
		cout<<(int *)ps[i]<<endl;
		if((si1=strlen(ps[0]))<(si2=strlen(ps[i])))
		{
			
			ps[0]=ps[i];
		}
	}
	return ps[0];
}
template <typename T>
void dismax(T p[],int n)
{
	cout<<maxn(p,n)<<endl;
}


int main()
{
	int size1,size2;
	int iar[6]={3,4,2,66,7,8};
	size1=sizeof(iar)/sizeof(int);
	double darr[]={3.0,4.5,3,5,6.0};
	size2=sizeof(darr)/sizeof(double);
	char *ps[5]={"ni","wohji","hiyiheie","hieid","iye"};
	cout<<"max string address:"<<(int *)maxn(ps,5)<<endl;
	dismax(iar,size1);
	dismax(darr,size2);
}
