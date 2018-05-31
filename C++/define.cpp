#include <iostream>
using namespace std;


#define STRING(X) #X
#define concat(x,y) x##y

int main()
{
	int xy=180;
	
	cout <<concat(x,y)<<endl;
	cout <<STRING(learning C++)<<endl;
	return 0;
}
