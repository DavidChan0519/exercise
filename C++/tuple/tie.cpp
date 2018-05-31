#include <iostream>
#include <tuple>
using namespace std;

int main()
{
	tuple<int, float> test = make_tuple(1,23.45);
	int a;
	float b;

	tie(a,b) = test;
	cout << "a:" << a << endl;
	cout << "b:" << b << endl;
	return 0;
}
