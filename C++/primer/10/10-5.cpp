#include <iostream>
#include "10-5.h"


cStack::cStack()
{
	mTop=0;
}

bool cStack::isempty() const
{
	return mTop==0;
}

bool cStack::isfull() const
{
	return mTop==MAX;
}

bool cStack::pop(Item &i)
{
	if(mTop>0)
	{
		i=mItems[--mTop];
		return true;
	}
	else 
		return false;
}
bool cStack::push(const Item &i)
{
	if(mTop<MAX)
	{
		mItems[mTop++]=i;
		return true;
	}
	else
		return false;
}
