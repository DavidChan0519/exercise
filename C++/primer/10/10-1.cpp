#include <iostream>
#include <cstring>
#include "10-1.h"

using namespace std;

cBankAccount::cBankAccount(char *name , char *Account, double Save)
{
	strncpy(mName,name,39);
	mName[39]='\0';
	strncpy(mAccount,Account,39);
	mAccount[39]='\0';
	mSave=Save;
	show();
}

cBankAccount::~cBankAccount()
{
	cout<<"��������������"<<endl;
	/*strncpy_s(mName,"no name",7);
	mName[39]='\0';
	strncpy_s(mAccount,"no Account",10);
	mAccount[39]='\0';
	mSave=0;*/
}

bool cBankAccount::Get(double sa)
{
	if(sa>0)
	{
		mSave-=sa;
		cout<<"ȡ������:"<<endl;
		show();
		return true;
	}
	else
		return false;
}

bool cBankAccount::Save(double sa)
{
	if(sa>0)
	{
		mSave+=sa;
		cout<<"�������"<<endl;
		show();
		return true;
	}
	else
		return false;
}

void cBankAccount::show() const
{
	cout<<"��������:"<<mName<<"  �˺�:"<<mAccount<<"  ���:"<<mSave<<endl;
}
