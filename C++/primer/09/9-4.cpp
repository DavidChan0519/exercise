#include <iostream>
#include "9-4.h"

using namespace std;

namespace SALES
{
	void setSales(Sales &s,const double ar[],int n)
	{
		double average=0;
		s.average=0;
		s.min=s.max=ar[0];
		for(int i=0;i<n;i++)
		{
			s.sales[i]=ar[i];
			if(s.max<ar[i])
				s.max=ar[i];
			if(s.min>ar[i])
				s.min=ar[i];
			average+=ar[i];
		}
		s.average=average/n;
	}

	void showSales(const Sales &s)
	{
		for(int i=0;i<QUARTERS;i++)
			cout<<"Sales["<<i<<"]:"<<s.sales[i]<<endl;
		cout<<"Sales Max:"<<s.max<<endl;
		cout<<"Sales Min:"<<s.min<<endl;
		cout<<"Sales average:"<<s.average<<endl;
	}

	void setSales(Sales &s)
	{
		double average=0;
		s.max=s.average=0;
		for(int i=0;i<QUARTERS;i++)
		{
			cout<<"Enter Sales["<<i<<"]:";
			cin>>s.sales[i];
			s.min=s.sales[0];
			if(s.max<s.sales[i])
				s.max=s.sales[i];
			if(s.min>s.sales[i])
				s.min=s.sales[i];
			average+=s.sales[i];
		}
		s.average=average/QUARTERS;
	}
}
		


