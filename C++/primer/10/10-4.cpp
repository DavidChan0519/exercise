#include <iostream>
#include "10-4.h"

using namespace SALES;

cSales::cSales()
{
	mAverage=mMax=mMin=0;
	for(int i=0;i<QUARTERS;i++)
		mSales[i]=0;
}

cSales::cSales(double ar[], int n)
{
	double Total=0;
	if(n<0)
		n=0;
	int limit=n<QUARTERS?n:QUARTERS;
	mAverage=mMax=mMin=0;
	if(limit>0)
		mMax=mMin=ar[0];
	for(int i=0;i<limit;i++)
	{
		mSales[i]=ar[i];
		if(mMax<ar[i])
			mMax=ar[i];
		else if(mMin>ar[i])
			mMin=ar[i];
		Total+=ar[i];
	}
	for(int i=limit;i<QUARTERS;i++)
		mSales[i]=0;
	if(limit>0)
		mAverage=Total/limit;
}
void cSales::setSales()
{
	using std::cout;
	using std::cin;
	double sa[QUARTERS];
        int i;
        for (i = 0; i < QUARTERS; i++)
        {
            cout << "Enter sales for quarter " << i + 1 << ": ";
            cin >> sa[i];
        }
        
        // create temporary object, copy to invoking object
        *this = cSales(sa, QUARTERS);
}
 

void cSales::showSales() const
{
	using std::cout;
	using std::endl;
	cout << "Sales:\n";
        for (int i = 0; i < QUARTERS; i++)
            cout << "Quarter " << i + 1 << ": $"
                 << mSales[i] << endl;
        cout << "Average: $" << mAverage << endl;
        cout << "Minimum: $" << mMin << endl;
        cout << "Maximum: $" << mMax << endl;
}
