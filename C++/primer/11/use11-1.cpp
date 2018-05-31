#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include "11-1.h"

int main()
{
    using namespace std;
    using CVECTOR::CVector;
    srand(time(0));     // seed random-number generator
	ofstream outFile;
	outFile.open("./11/test11-1.txt");
	if(!outFile.is_open())
	{
		cout<<"open file failed!\n";
		exit(EXIT_FAILURE);
		return 0;
	}
    double direction;
    CVector step;
    CVector result(0.0, 0.0);
    unsigned long steps = 0;
    double target;
    double dstep;
    cout << "Enter target distance (q to quit): ";
    //while (cin >> target)
    //{
	//add line
		cin>>target;
	///
		cout << "Enter step length: ";
        if (!(cin >> dstep))
            //break;
		//reset line
			return 0;
		//
		outFile<<"Target Distance:"<<target<<","<<"Step Size:"<<dstep<<endl;
        while (result.magval() < target)
        {
			outFile<<steps<<":"<<result<<endl;
            direction = rand() % 360;
            step.set(dstep, direction, 'p');
            result = result + step;
            steps++;
        }
        cout << "After " << steps-1 << " steps, the subject "
            "has the following location:\n";
        cout << result << endl;
		outFile<<"Ater "<<steps-1<<" steps,the subject has"
			" the following location:\n";
		outFile<<result<<endl;
        result.polar_mode();
        cout << " or\n" << result << endl;
		outFile<<" or\n"<<result<<endl;
        cout << "Average outward distance per step = "
            << result.magval()/steps << endl;
		outFile<<"Average outward distance per step ="<<result.magval()/steps<<endl;
		outFile.close();
        steps = 0;
        result.set(0.0, 0.0);
    //    cout << "Enter target distance (q to quit): ";
    //}
    //cout << "Bye!\n";

    return 0; 
}