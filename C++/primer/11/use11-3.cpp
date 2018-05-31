// randwalk.cpp -- using the Vector class
// compile with the vect.cpp file
#include <iostream>
#include <cstdlib>      // rand(), srand() prototypes
#include <ctime>        // time() prototype
#include "11-2.h"	//link 11-2.h and 11-2.cpp
int main()
{
    using namespace std;
    using CVECTOR::CVector;
    srand(time(0));     // seed random-number generator
    double direction;
    CVector step;
    CVector result(0.0, 0.0);
    unsigned long steps = 0;
    double target;
    double dstep;

	int N;
	cout<<"Enter test count:";
	if(!(cin>>N))
	{
		cout<<"Error! you must Enter int number!\n";
		return 0;
	}

	cout << "Enter target distance (q to quit): ";
	int *p=new int[N];
		

	cin>>target;
	cout << "Enter step length: ";
	if (!(cin >> dstep))
		return 0;
	for(int i=0;i<N;i++)
	{
		while (result.magval() < target)
		{
			direction = rand() % 360;
			step.set(dstep, direction, 'p');
			result = result + step;
			steps++;
		}
		cout << "After " << steps << " steps, the subject "
			"has the following location:\n";
		cout << result << endl;
		result.polar_mode();
	    cout << " or\n" << result << endl;
	    cout << "Average outward distance per step = "
	        << result.magval()/steps << endl;
		cout<<endl;
		p[i]=steps;
	    steps = 0;
	    result.set(0.0, 0.0);
		    
	}
	for(int i=0;i<N;i++)
	{
		for(int j=i+1;j<N;j++)
		{
			if(p[i]<p[j])
			{
				int temp;
				temp=p[i];
				p[i]=p[j];
				p[j]=temp;
			}
		}
	}
	int sum=0;
	for(int i=0;i<N;i++)
	{
		sum+=p[i];
	}
	sum=sum/N;
	cout<<"Max steps:"<<p[0]<<endl;
	cout<<"Min steps:"<<p[N-1]<<endl;
	cout<<"Average steps:"<<sum<<endl;
	cout << "Bye!\n";
	delete [] p;
    return 0; 
}
