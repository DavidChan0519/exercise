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
	cGolf golf2("zhao hang",0);//���ַ��Ļ����һ����������
	golf2.show();
	cout<<endl;
	//cout<<"use temp so ~cGolf!\n";
	cout<<"golf2:"<<endl;
	golf2=cGolf("haing",4);//��������ʱ���� cGolf����golf2����������ɾ����������ʱ����
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
	return 0;//���ｫ���������������ã�����golf2��Ȼ����golf;
}