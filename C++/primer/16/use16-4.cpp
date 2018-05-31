#include <iostream>
#include <algorithm>// sort();
using namespace std;

#define MAX 10

int reduce(long ar[],int n);//排序，删除重复的值，返回缩减后数组元素的数目
void show(const long ar[],int n=MAX);
int main()
{
	long iMyaray[MAX]={13,44,55,2,3,22,56,78,98,98};
	show(iMyaray,sizeof(iMyaray)/sizeof(int));

	int newsize=reduce(iMyaray,MAX);
	show(iMyaray,newsize);
	return 0;
}

int reduce(long ar[],int n)
{
	std::sort(ar,ar+n);
	long *past_end=std::unique(ar,ar+n);
	return past_end-ar;
}

void show(const long ar[],int n)
{
	for(int i=0;i<n;i++)
		cout<<ar[i]<<" ";
	cout<<endl;
}

	

