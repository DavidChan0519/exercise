#include <iostream>
#include "10-3.h"
using namespace std;

int main()
{
	cout<<"golf1:"<<endl;
	cGolf golf;
	golf.show();
	cout<<endl;
	
	cout<<"golf2:"<<endl;
	cGolf golf2("zhao hang",0);//这种风格的会调用一次析构函数
	golf2.show();
	cout<<endl;
	//cout<<"use temp so ~cGolf!\n";
	cout<<"golf2:"<<endl;
	golf2=cGolf("haing",4);//创建了临时变量 cGolf赋给golf2后，析构函数删除创建的临时变量
	golf2.show();
	cout<<endl;

	cout<<"golf3:"<<endl;
	cGolf golf3;
	golf3.setGolf("nih hal",44);
	golf3.show();
	cout<<endl;
	
	cout<<"\ngolf2:"<<endl;
	golf2.show();
	cout<<endl;
	return 0;//这里将会有两个析构调用，先是golf2，然后是golf;
}