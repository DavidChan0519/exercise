// stock2.h -- augmented version
#ifndef _12_3_H
#define _12_3_H
#include <iostream>
class Stock
{
private:
    char *company;
    int shares;
    double share_val;
    double total_val;
	static int StockNum;
    void set_tot() { total_val = shares * share_val; }
public:
    Stock();        // default constructor
    Stock(const char * co, int n = 0, double pr = 0.0);
	Stock(const Stock &s);
    ~Stock();       //  destructor
    void buy(int num, double price);
    void sell(int num, double price);
    void update(double price);
	Stock &operator=(const Stock &s);


    const Stock & topval(const Stock & s) const;
	friend std::ostream &operator <<(std::ostream &os,const Stock &s);
	
};

#endif
