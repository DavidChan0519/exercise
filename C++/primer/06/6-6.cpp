#include <iostream>
#include <string>

using namespace std;
struct s_pay{
	string name;
	double money;
};

int main()
{
	cout<<"Enter number of benefactor:";
	int benor;
	cin>>benor;
	cin.get();
	s_pay *pay=new s_pay[benor];
	int GrandCount=0,ParCount=0;
	for(int i=0;i<benor;i++)
	{
		cout<<"Enter benefactor "<<i+1<<"'s name:";
		getline(cin,pay[i].name);
		cout<<"Enter benefactor "<<i+1<<"'s money:";
		cin>>pay[i].money;
		cin.get();
	}
	cout<<"The Grand Patrons is:\n";
	for(int i=0;i<benor;i++)
	{
		if(pay[i].money>=10000)
		{
			cout<<"name:"<<pay[i].name<<"  money:"<<pay[i].money<<"\n";
			GrandCount++;
		}
		
	}
	if(!GrandCount)
			cout<<"none\n";
	cout<<"other Patrons is:\n";
	for(int i=0;i<benor;i++)
	{
		if(pay[i].money<10000)
		{
			cout<<"name:"<<pay[i].name<<"  money:"<<pay[i].money<<"\n";
			ParCount++;
		}
	}
	if(!ParCount)
		cout<<"none\n";
	delete [] pay;
	return 0;
}
