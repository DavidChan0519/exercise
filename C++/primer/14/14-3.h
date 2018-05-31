#include <iostream>
#include <string>


template <class Type>
class Queue
{
private:
// class scope definitions
    // Node is a nested structure definition local to this class
    struct Node { Type item; struct Node * next;};
    enum {Q_SIZE = 10};
// private class members
    Node * front;       // pointer to front of Queue
    Node * rear;        // pointer to rear of Queue
    int items;          // current number of items in Queue
    const int qsize;    // maximum number of items in Queue
    // preemptive definitions to prevent public copying
    Queue(const Queue & q) : qsize(0) { }
    Queue & operator=(const Queue & q) { return *this;}
public:
    Queue(int qs = Q_SIZE); // create queue with a qs limit
    ~Queue();
    bool isempty() const;
    bool isfull() const;
    int queuecount() const;
    bool enqueue(const Type &item); // add item to end
    bool dequeue(Type &item);       // remove item from front
};

class Worker
{
private:
	std::string fullname;
	double id;
public:
	Worker();
	Worker(char *f,double i=0);
	Worker(std::string f,double i);
	//Worker(Worker &w){fullname=w.fullname;id=w.id;};
	//Worker &operator =(const Worker &w){if(this==&w)return *this;else fullname=w.fullname;id=w.id;return *this;};
	std::string getfullname()const{return fullname;};
	double getid()const {return id;};
	void setworker();
	void show()const;
};


template <class Type>
Queue<Type>::Queue(int qs):qsize(qs)
{
	front=rear=NULL;
	items=0;
}
template <class Type>
bool Queue<Type>::isempty() const
{
	return items==0;
}

template <class Type>
bool Queue<Type>::isfull() const
{
	return items==qsize;
}

template <class Type>
bool Queue<Type>::dequeue(Type &item)
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

template <class Type>
bool Queue<Type>::enqueue(const Type &item)
{
	if (isfull())
        return false;
    Node * add = new Node;  // create node
    if (add == NULL)
        return false;       // quit if none available
    add->item = item;       // set node pointers
    add->next = NULL;
    items++;
    if (front == NULL)      // if queue is empty,
        front = add;        // place item at front
    else
        rear->next = add;   // else place at rear
    rear = add;             // have rear point to new node
    return true;
}

template <class Type>
int Queue<Type>::queuecount() const
{
	return items;
}

template <class Type>
Queue<Type>::~Queue()
{
	Node *temp;
	while(front!=NULL)
	{
		temp=front;
		front=front->next;
		delete temp;
	}
}

Worker::Worker()
{
	fullname="";
	id=0;
}

Worker::Worker(char *f, double i)
{
	fullname=f;
	id=i;
}

Worker::Worker(std::string f, double i)
{
	fullname=f;
	id=i;
}

void Worker::setworker()
{
	std::cout<<"Enter Worker's Name:";
	getline(std::cin,fullname);
	std::cout<<"Enter Worker's Id:";
	std::cin>>id;
	std::cin.get();
}

void Worker::show() const
{
	std::cout<<"Name: "<<fullname<<std::endl;
	std::cout<<"id: "<<id<<std::endl;
}




