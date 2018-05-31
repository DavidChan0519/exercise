#include <iostream>
#include "10-6.h"

using namespace std;

int main()
{
	Move mo1;
	mo1.showmove();
	cout<<"mo1 reset:";
	mo1.reset(2,5);
	mo1.showmove();
	Move mo2(1,1);
	mo2.showmove();
	mo2=mo2.add(mo1);
	cout<<"mo2 add mo1:";
	mo2.showmove();
	cout<<"mo2 reset:";
	mo2.reset();
	mo2.showmove();
	return 0;
}
