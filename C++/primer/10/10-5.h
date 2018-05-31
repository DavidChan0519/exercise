#ifndef _10_5_H
#define _10_5_H

struct customer{
	char fullname[35];
	double payment;
};

typedef customer Item;

class cStack{
	enum {MAX=10};
	Item mItems[MAX];
	int mTop;
public:
	cStack();
	bool isempty()const;
	bool isfull()const;
	bool push(const Item &i);
	bool pop(Item &i);
};
#endif