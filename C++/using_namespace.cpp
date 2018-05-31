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

using namespace First_space;

int main()
{
	func();
	return 0;
}
