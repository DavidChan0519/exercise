#include <iostream>
using namespace std;

template <class T>
T max5(T a[])
{
	//T temp;
	T Max=a[0];
	for(int i=1;i<5;i++)
	{
		if(a[i]>Max)
			Max=a[i];
	}
	return Max;
}

int main()
{
	int c[5]={2,1,4,5,3};
	int iMax=max5(c);
	double dMax;
	cout<<"Max:"<<iMax<<endl;
	double b[5]={2.3,4.5,11.5,22.3,4.4};
	dMax=max5(b);
	cout<<"Max:"<<dMax<<endl;
	return 0;
}
			
				
