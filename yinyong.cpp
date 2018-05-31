#include <iostream>
using namespace std;


int swap(int &a, int &b)
{
	int temp;
	
	temp = a;
	a = b;
	b = temp;
	return 0;

}

int main()
{

	int A = 10;
	int B = 20;
	
	cout << "before:"<<endl;
	cout << "A: " << A <<endl;
	cout << "B: " << B <<endl;

	swap(A,B);
	
	cout << "after:"<< endl;
	cout << "A: " << A <<endl;
	cout << "B: " << B <<endl;
	
	return 0;
}
