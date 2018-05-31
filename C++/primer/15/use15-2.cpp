#include <iostream>
#include "15-2.h"
#include <cmath>
using namespace std;

double hmean(double a,double b) throw(std::logic_error &);
double gmean(double a,double b) throw(std::logic_error &);

int main()
{
	double x,y,z;
	cout<<"Enter two numbers: ";;
	while(cin>>x>>y)
	{
		try{
			z = hmean(x,y);
            cout << "Harmonic mean of " << x << " and " << y
                << " is " << z << endl;
            cout << "Geometric mean of " << x << " and " << y
                << " is " << gmean(x,y) << endl;
            cout << "Enter next set of numbers <q to quit>: ";
			
		}
		catch (hmeanecp &bg)
		{
			cout<<bg.what();
			cout<<"try again.\n";
			continue;
		}
		
		catch (gmeanecp &ge)
		{
			cout<<ge.what();
			cout<<"Sorry ,you don't get to play any more.\n";
			break;
		}
	}
	cout<<"Done!\n";
	return 0;
}



double hmean(double a,double b) throw(std::logic_error &)
{
	if(a==-b)
		throw hmeanecp();
	return 2.0 * a * b / (a+b);
}

double gmean(double a,double b) throw(std::logic_error &)
{
	if(a<0 || b<0)
		throw gmeanecp();
	return sqrt(a * b);
}