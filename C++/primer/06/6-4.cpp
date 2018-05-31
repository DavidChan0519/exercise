#include <iostream>
#include <string>
using namespace std;
const int strsize=80;

struct bop{
	char fullname[strsize];
	char title[strsize];
	char bopname[strsize];
	int preference;
	bop(const char f[strsize]="NULL",const char ti[strsize]="NULL",const char bop[strsize]="NULL",int pre=-1){
		strcpy_s(fullname,strlen(f)+1,f);
		strcpy_s(title,strlen(ti)+1,ti);
		strcpy_s(bopname,strlen(bop)+1,bop);
		preference=-1;
	}
};

void display(const bop &a,int n=0) 
{
	switch(n)
	{
	case 0:
		cout<<a.fullname<<"\n";
		break;
	case 1:
		cout<<a.title<<"\n";
		break;
	case 2:
		cout<<a.bopname<<"\n";
		break;
	};
}
int main()
{
	bop b[5];
	string str[5]={"a.display by name\n","b.display by title\n","c.display by bopname\n","d.display by preference\n",
		"q.quit\n"};
	
	char choice;
	for(int i=0;i<5;i++)
		cout<<str[i];
	cout<<"Enter your choice:";
	cin>>choice;
	for(int i=0;i<5;i++)
	{
		
		if(choice=='d')
			display(b[i],b[i].preference);
		else if(choice=='a')
			display(b[i]);
		else if(choice=='b')
			display(b[i],1);
		else if(choice=='c')
			display(b[i],2);
		else if(choice=='q')
			break;
	}
	return 0;
}


