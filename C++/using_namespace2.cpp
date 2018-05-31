#include <iostream>
using std::cout;


namespace First_space
{
	void func(){
		cout << "1st namespace func" <<std::endl;
	}

	
}

namespace Second_space
{
	void func() {
		cout << "2nd namespace func" << std::endl;
	}
}

using namespace Second_space;

int main()
{
	func();
	return 0;
}
