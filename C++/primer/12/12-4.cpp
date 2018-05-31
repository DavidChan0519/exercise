#include <iostream>
#include "12-4.h"

using namespace std;

Stack::Stack(int n)
{
	pitems=new Item[n];
	size=n;
	top=0;
}

Stack::Stack(const Stack &st)
{
}

Stack::~Stack()
{
	delete [] pitems;
}

bool Stack::isempty() const
{
	return top==0 ? true:false;
}
bool Stack::isfull() const
{
	return top==size ? true:false;
}

bool Stack::pop(Item &item)
{
	if(top>0)
	{
		item=pitems[--top];
		return true;
	}
	else
		return false;
}
bool Stack::push(const Item &item)
{
	if(top<size)
	{
		pitems[top++]=item;
		return true;
	}
	else
		return false;
}
