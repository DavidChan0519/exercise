#include <iostream>
using namespace std;

typedef struct demo
{

	int a;
	int b;
}stDemo;


void print(stDemo stCase)
{
	cout << "1st mem: " << stCase.a
	<< " 2nd mem: " << stCase.b << endl;

	stCase.a = 555;
	stCase.b = 777;
}


int main()
{
	stDemo T1;
	
	T1.a = 4444;
	T1.b = 8888;

	print(T1);
	print(T1);
	return 0;

}



