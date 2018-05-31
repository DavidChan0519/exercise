#include "10-8.h"

cList::cList()
{
	count=0;
}

bool cList::isempty()
{
	return count==0;
}

bool cList::isfull()
{
	return count==MAXLIST;
}

int cList::itemcount()
{
	return count;
}

bool cList::additem(Item it)
{
	if(count==MAXLIST)
		return false;
	else
		item[count++]=it;
	return true;
}

void cList::transverse(void (*fp)(Item it))
{
	for(int i=0;i<count;i++)
	{
		(*fp)(item[i]);
	}
}