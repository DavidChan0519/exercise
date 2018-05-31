#include <iostream>
using namespace std;

class Distance
{
public:
	Distance()
	{	
		feet = 0;
		inches = 0;
	}

	Distance(int i, int j)
	{
		feet = i;
		inches = j;
	}

	void showdistance()
	{
		cout << "F" << feet << "inches" << inches <<endl;
	}

	Distance operator-()
	{
		feet = -feet;
		inches = -inches;
		return Distance(feet,inches);
	}
	
private:
	int feet;
	int inches;
};


int main()
{
	Distance D1(10,-20),D2(-4,34);
	
	-D1;
	D1.showdistance();

	-D2;
	D2.showdistance();

}
