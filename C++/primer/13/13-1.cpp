#include <iostream>
#include "13-1.h"

Cd::Cd()
{
	strcpy_s(performers,"No Performers");
	performers[50]='\0';
	strcpy_s(label,"No label");
	label[20]='\0';
	playtime=0.0;
	selections=0;
};

Cd::Cd(char *s1, char *s2, int n, double x)
{
	size_t size=0;
	size=strlen(s1);
	strcpy_s(performers,size+1,s1);
	size=strlen(s2);
	strcpy_s(label,size+1,s2);
	selections=n;
	playtime=x;
};

void Cd::Report() const
{
	using std::cout;
	using std::endl;
	std::cout<<"Performers: "<<performers<<endl;
	cout<<"Label: "<<label<<endl;
	cout<<"selections: "<<selections<<endl;
	cout<<"Playtime: "<<playtime<<endl;
}

Classic::Classic():Cd()
{
	strcpy_s(mainstr,"No MainStr");
}

Classic::Classic(char *ms, char *s1, char *s2, int n, double x):Cd(s1,s2,n,x)
{
	strcpy_s(mainstr,strlen(ms)+1,ms);
}

void Classic::Report() const
{
	Cd::Report();
	std::cout<<"MainStr: "<<mainstr<<std::endl;
}
