#include <iostream>
#include <cstring>
//#include <cctype>
using namespace std;

//void mytoupper(std::string &a)
//{
//	using std::cout;
//	size_t size;
//	size=a.size();
//	for(size_t i=0;i<size;i++)
//		cout.put(toupper(a[i]));
//}
//
struct stringy{
	char *str;
	int ct;
};
void set(stringy &a,const char *pt)
{
	a.ct=strlen(pt);
	a.str=new char[a.ct+1];
	strcpy_s(a.str,a.ct+1,pt);
}
void show(stringy &a,const int n=1)
{
	for(int i=0;i<n;i++)
	{
		cout<<a.str<<endl;
	}
}
void show(const char *pt,const int n=1)
{
	for(int i=0;i<n;i++)
	{
		cout<<pt<<endl;
	}
}

int main()
{
	stringy beany;
	char testing[]="Reality isn't what it used to be.";
	set(beany,testing);
	show(beany);
	show(beany,2);
	testing[0]='D';
	testing[1]='u';
	show(testing);
	show(testing ,3);
	show("Done! ");
	//mytoupper(name);
	return 0;
}
//
