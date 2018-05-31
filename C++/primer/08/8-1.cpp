#include <iostream>

using namespace std;

void display(const char *str,int n=0)
{
	static int use=0;
	++use;
	if(n==0)
		cout<<str<<'\n'<<endl;
	else
		for(int i=0;i<use;i++)
		{
			cout<<str<<endl;
		}
}

int main()
{
	char str[50]="ni hao ma?";
	display(str);
	display(str,3);
	display(str,4);

	return 0;
}

