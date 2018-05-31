#include <iostream>
using namespace std;

class Stock
{
private :
	string m_company;
	int m_shares;
public:
	Stock();
	void show()const;
	Stock(const char *cp, int n=9);
};

Stock::Stock()
{
	cout << "calling constructive function" << endl;
}

Stock::Stock(const char *cp, int n)
{
        m_company=cp;
	m_company[10]='\0';
	m_shares = n;
}

void Stock::show()const
{
	cout << m_company << endl;
	cout << m_shares << endl;
}


int main()
{
	Stock st;
	Stock mt("chengwei",200);
	st = mt;
	Stock *pt = new Stock("Bitmain",100);

	Stock at[3]={
		Stock("array1",1),
		Stock(),
		Stock("array2",2),

	};

	at[0].show();
	at[2].show();

	pt->show();
	st.show();
	return 0;	

}
