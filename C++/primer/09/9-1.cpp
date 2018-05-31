//golf.cpp
#include "9-1.h"

void setgolf(golf &g,const char *name,int hc)
{
	size_t size=0;
	size=strlen(name)+1;
	strcpy_s(g.fullname,size,name);
	g.handicap=hc;
}

int setgolf(golf &g)
{
	using std::cin;
	using std::cout;
	cout<<"Enter name and level:";
	while(!(cin>>g.fullname>>g.handicap))
	{
		cout<<"Enter failed!\n";
		return 1;
	}
	return 0;
}

void handicap(golf &g,int hc)
{
	g.handicap=hc;
}

void showgolf(const golf &g)
{
	using namespace std;
	cout<<"name:"<<g.fullname<<endl;
	cout<<"level:"<<g.handicap<<endl;
}


int main()
{
	using namespace std;
	golf ann;
	setgolf(ann,"Ann Birdfree",24);
	showgolf(ann);

	golf andy;
	setgolf(andy);
	showgolf(andy);

	return 0;
}