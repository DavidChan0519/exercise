#include <iostream>
#include "cow.h"
using namespace std;
int main()
{
	Cow cow1;
	Cow cow2("Ä¸µÄ","yes",20);
	Cow cow3=cow2;
	//cow1.ShowCow();
	cow1=cow3;
	cow2.ShowCow();
	cow3.ShowCow();
	cow1.ShowCow();
	return 0;
}
