// dma.h  -- inheritance and dynamic memory allocation
#ifndef _13_3_H
#define _13_3_H
#include <iostream>
class ABC
{
private:
	char *label;
	int rating;
public:
	ABC(const char *l="NULL",int r=0);
	ABC(const ABC &a);
	char *getlablel()const {return label;};
	int getrating()const {return rating;};
	virtual ~ABC()=0;
	virtual void View()const;
	ABC &operator=(const ABC &a);
	friend std::ostream &operator <<(std::ostream &os,const ABC &a);
};
//  Base Class Using DMA
class baseDMA:public ABC
{
private:
public:
    baseDMA(const char * l = "null", int r = 0);
	void View()const;
};

// derived class without DMA
// no destructor needed
// uses implicit copy constructor
// uses implicit assignment operator
class lacksDMA :public ABC
{
private:
    enum { COL_LEN = 40};
    char color[COL_LEN];
public:
    lacksDMA(const char * c = "blank", const char * l = "null",
              int r = 0);
    lacksDMA(const char * c, const lacksDMA & rs);
	virtual void View()const;
	//~lacksDMA(){};
    friend std::ostream & operator<<(std::ostream & os, 
                                     const lacksDMA & rs);
};

// derived class with DMA
class hasDMA :public ABC
{
private:
    char * style;
public:
    hasDMA(const char * s = "none", const char * l = "null",
              int r = 0);
    hasDMA(const char * s, const ABC & rs);
    hasDMA(const hasDMA & hs);
    ~hasDMA();
    hasDMA & operator=(const hasDMA & rs);  
	virtual void View()const;
    friend std::ostream & operator<<(std::ostream & os, 
                                     const hasDMA & rs);
};

#endif
