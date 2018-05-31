#include <iostream>
using namespace std;

namespace first_space
{
	void func()
	{
		cout<<"1st func namespace"<<endl;
	}
}

namespace second_space
{
	void func()
	{
		cout << "2nd func namespace" << endl;
	}
}


int main()
{
	first_space::func();
	second_space::func();
	return 0;
}
