#include <iostream>
using namespace std;


template <typename T>
inline T const & Max(T const &a, T const &b)
{
	return (a>b?a:b);
}


int main()
{
	int a=10;
	int b=89;
	int c = Max(a,b);
	
	cout << "the max value of int " << c <<endl;

	double m= 10.11;
	double n= 20.33;
	double l = Max(m,n);
	cout << "the max value of double " << l << endl;

	string str1 = "hello";
	string str2 = "world";
	cout << "the max str of string " << Max(str1, str2) << endl; 
	return 0;
}
