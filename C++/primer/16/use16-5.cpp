#include <iostream>
#include <algorithm>
#include <iomanip>
#include <string>
using namespace std;

template<class T>
int reduce(T ar[],int n)
{
	std::sort(ar,ar+n);
	T *past_end;
	past_end=std::unique(ar,ar+n);
	return past_end-ar;
}

template<class T>
void show(T ar[],int n)
{
	for(int i=0;i<n;i++)
		cout<<std::setw(3)<<ar[i]<<" ";
	cout<<endl;
}

int main()
{
	long iMyaray[]={13,44,55,2,3,22,56,78,98,98};
	show(iMyaray,sizeof(iMyaray)/sizeof(int));

	int newsize=reduce(iMyaray,sizeof(iMyaray)/sizeof(long));
	show(iMyaray,newsize);

	string str[5]={"ni hao","ni hao","eritr ","eritr ","eir"};
	show(str,5);
	newsize=reduce(str,5);
	show(str,newsize);
	return 0;
}

