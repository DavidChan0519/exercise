#include <iostream>
#include <string>
#include <fstream>
using namespace std;
struct s_pay{
	string name;
	double money;
};


int main()
{
	ofstream outfile;
	
	char filename[80];
	cout<<"Enter open filename:";
	cin.getline(filename,80);
	outfile.open(filename,ios_base::out);
	if(!outfile.is_open())
	{
		cout<<"open file failed!\n";
		exit(EXIT_FAILURE);
	}
	cout<<"Enter number of benefactor:";
	int benor;
	cin>>benor;
	cin.get();
	outfile<<benor<<endl;
	s_pay *pay=new s_pay[benor];
	//int GrandCount=0,ParCount=0;
	for(int i=0;i<benor;i++)
	{
		cout<<"Enter benefactor "<<i+1<<"'s name:";
		getline(cin,pay[i].name);
		outfile<<pay[i].name<<endl;
		cout<<"Enter benefactor "<<i+1<<"'s money:";
		cin>>pay[i].money;
		cin.get();
		outfile<<pay[i].money<<endl;
	}
	outfile.close();
	//char filename[80];
	int GrandCount=0,ParCount=0;
	ifstream infile;
	cout<<"Enter open filename:";
	cin.getline(filename,80);
	infile.open(filename,ios_base::in);
	if(!infile.is_open())
	{
		cout<<"open file failed!\n";
		exit(EXIT_FAILURE);
	}
	//int benor;
	infile>>benor;
	while(infile.get()!='\n')
		continue;
	cout<<"number of benefactor:"<<benor<<endl;
	//s_pay *pay=new s_pay[benor];
	for(int i=0;i<benor;i++)
	{
		getline(infile,pay[i].name);
		//while(infile.get()!='\n')
			//continue;
		infile>>pay[i].money;
		//infile.clear();
		while(infile.get()!='\n')
			continue;
			
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
	infile.close();
	delete [] pay;
	return 0;
}
