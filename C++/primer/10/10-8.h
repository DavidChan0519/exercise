#ifndef _10_8_H
#define _10_8_H

const int SIZE=45;
struct film{
	char title[SIZE];
	int rating;
};

typedef struct film Item;
const int MAXLIST=10;
class cList{
private:
	Item item[MAXLIST];
	int count;
public:
	cList();
	bool isempty();
	bool isfull();
	int itemcount();
	bool additem(Item it);
	void transverse(void (*fp)(Item it));
};
#endif




