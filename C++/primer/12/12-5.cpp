#include "12-5.h"
#include <iostream>
#include <ctime>  //srand() time();

Queue::Queue(int qs):qsize(qs)
{
	front=rear=NULL;
	items=0;	
}


bool Queue::isempty() const
{
	return items==0 ? true:false;
}
bool Queue::isfull() const
{
	return items==qsize ? true:false;
}

bool Queue::enqueue(const Item &item)
{
	if(isfull())
		return false;
	Node *add=new Node;
	if(add==NULL)
		return false;
	add->item=item;
	add->next=NULL;
	items++;
	if(front==NULL)
		front=add;
	else
		rear->next=add;
	rear=add;
	return true;
}
bool Queue::dequeue(Item &item)
{
	if(front==NULL)
		return false;
	item=front->item;
	items--;
	Node *temp=front;
	front=front->next;
	delete temp;
	if(items==0)
		rear=NULL;
	return true;
}
Queue::~Queue()
{
	Node *temp;
	while(front!=NULL)
	{
		temp=front;
		front=front->next;
		delete temp;
	}
}
int Queue::queuecount() const
{
	return items;
}

void Customer::set(long when)
{
	processtime=rand()%3+1;
	arrive=when;
}