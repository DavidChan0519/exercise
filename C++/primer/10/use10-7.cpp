#include <iostream>
#include "10-7.h"

using namespace std;

int main()
{
	cPlorg plorg;
	plorg.showplorg();
	cPlorg pl("zhao hang");
	pl.showplorg();
	pl.setCI(60);
	pl.showplorg();
	return 0;
}
