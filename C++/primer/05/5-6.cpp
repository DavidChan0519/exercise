#include <iostream>
#include <string>
using namespace std;
struct car{
	string name;
	int year;
};

int main()
{
	int count=0;
	cout<<"How many cars do you wish to catalog?";
	cin>>count;//cin将回车输入的换行符留在了输入的队列中了
	cin.get();//读取换行符，以便跳过，否则在getline时将直接读取换行符
	car *p=new car[count];
	for(int i=0;i<count;i++)
	{
		cout<<"Car #"<<i+1<<endl;
		cout<<"please enter the make:";
		getline(cin,p[i].name);
		cout<<"please enter the year made:";
		//cin.clear();
		cin>>p[i].year;
		cin.get();
	}
	cout<<"Here is your collection:"<<endl;
	for(int i=0;i<count;i++)
	{
		cout<<p[i].year<<" "<<p[i].name<<endl;
	}
	delete [] p;
	return 0;
}