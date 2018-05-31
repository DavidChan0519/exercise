// stock2.cpp -- improved version
#include <iostream>
#include "12-3.h"
int Stock::StockNum=0;
// constructors
Stock::Stock()        // default constructor
{
	company=new char[1];
	company[0]='\0';
    shares = 0;
    share_val = 0.0;
    total_val = 0.0;
	StockNum++;
}

Stock::Stock(const char * co, int n, double pr)
{
	size_t len=0;
	len=strlen(co);
	company=new char[len+1];
	strcpy_s(company,len+1,co);

    if (n < 0)
    {
        std::cerr << "Number of shares can't be negative; "
                   << company << " shares set to 0.\n";
        shares = 0;
    }
    else
        shares = n;
    share_val = pr;
    set_tot();
	StockNum++;
}
Stock::Stock(const Stock &s)
{
	company=new char[strlen(s.company)+1];
	strcpy_s(company,strlen(s.company)+1,s.company);
	share_val=s.share_val;
	shares=s.shares;
	total_val=s.total_val;
	StockNum++;
}

// class destructor
Stock::~Stock()        // quiet class destructor
{
	std::cout<<company<<"  destructor!";
	delete [] company;
	StockNum--;
	std::cout<<"  StockNum: "<<StockNum<<std::endl;
}

// other methods
void Stock::buy(int num, double price)
{
     if (num < 0)
    {
        std::cerr << "Number of shares purchased can't be negative. "
             << "Transaction is aborted.\n";
    }
    else
    {
        shares += num;
        share_val = price;
        set_tot();
    }
}

void Stock::sell(int num, double price)
{
    using std::cerr;
    if (num < 0)
    {
        cerr << "Number of shares sold can't be negative. "
             << "Transaction is aborted.\n";
    }
    else if (num > shares)
    {
        cerr << "You can't sell more than you have! "
             << "Transaction is aborted.\n";
    }
    else
    {
        shares -= num;
        share_val = price;
        set_tot();
    }
}

void Stock::update(double price)
{
    share_val = price;
    set_tot();
}

//void Stock::show() const
//{
//    using std::cout;
//    using std::endl;
//    cout << "Company: " << company
//        << "  Shares: " << shares << endl
//        << "  Share Price: $" << share_val
//        << "  Total Worth: $" << total_val << endl; 
//}

const Stock & Stock::topval(const Stock & s) const
{
    if (s.total_val > total_val)
        return s;
    else
        return *this; 
}

std::ostream &operator <<(std::ostream&os,const Stock &s)
{
	os<<"name: "<<s.company
	  <<" Shares: "<<s.shares <<std::endl
	  <<" Share Price: $" <<s.share_val
	  <<" Total Worth: $" <<s.total_val<<std::endl;
	os<<" StockNum: "<<s.StockNum<<std::endl;
	return os;
}

Stock &Stock::operator =(const Stock &s)
{
	if(this==&s)
		return *this;
	delete [] company;
	company=new char[strlen(s.company)+1];
	strcpy_s(company,strlen(s.company)+1,s.company);
	share_val=s.share_val;
	shares=s.shares;
	total_val=s.total_val;
	return *this;
}