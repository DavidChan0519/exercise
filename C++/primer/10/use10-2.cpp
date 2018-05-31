#include <iostream>
#include "10-2.h"
using namespace std;
int main()
{
	Person one;
	Person tow("Smythecraft");
	Person three("dimwiddy","sam");
	one.Show();
	cout<<endl;
	one.FormalShow();
	tow.Show();
	tow.FormalShow();
	three.Show();
	three.FormalShow();
	return 0;
}