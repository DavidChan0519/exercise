#include <iostream>
using namespace std;

const int LEN=80;
struct sCandyBar{
	char name[LEN];
	double Weight;
	int Caluli;
};

void display(sCandyBar &a,const char *na="Millennium Munch",const double w=2.85,const int c=350)
{
	strcpy_s(a.name,strlen(na)+1,na);
	a.Weight=w;
	a.Caluli=c;
	cout<<"name:"<<a.name<<endl;
	cout<<"Weight:"<<a.Weight<<endl;
	cout<<"Caluli:"<<a.Caluli<<endl;
}

int main()
{
	sCandyBar b;
	display(b);
	display(b,"zhaoh hang hiaaie",2.34,50);
	return 0;
}

