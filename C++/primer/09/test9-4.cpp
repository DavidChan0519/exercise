#include <iostream>
#include "9-4.h"
using namespace std;
using namespace SALES;

int main()
{
	double ar[]={4.5,5.5,6,5,7,5};
	Sales s;
	setSales(s,ar,4);
	showSales(s);
	setSales(s);
	showSales(s);
	return 0;
}