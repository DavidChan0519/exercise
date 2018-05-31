#include <iostream>
using namespace std;


namespace First_space
{
	void func(){
		cout << "1st namespace func" <<endl;
	}

	
}

namespace Second_space
{
	void func() {
		cout << "2nd namespace func" << endl;
	}
}


int main()
{
	First_space::func();
	Second_space::func();
	return 0;
}
