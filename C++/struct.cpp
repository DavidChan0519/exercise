#include <iostream>
using namespace std;

struct thing {
	char *pstr;
	int a;

};

int main()
{
	thing Demo ={"hello", 101};

	cout <<"str:"<<Demo.pstr<<endl;
	cout <<"int:"<<Demo.a<<endl;
	return 0;
}
