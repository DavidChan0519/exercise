#include <iostream>
using namespace std;

class BOX
{
public:
	BOX(int i=1, int j=2, int k=3)
	{
		a = i;
		b = j;
		c = k;
	}
	inline int afunc()
	{
		cout << this->a<<endl;
	}
	
	inline int bfunc()
	{
		cout << this->b <<endl;
	}

	inline int cfunc()
	{
		cout << this->c <<endl;
	}

private:
	int a;
	int b;
	int c;
};


int main()
{
	BOX T1;
	BOX T2(4,5,6);
	
	T1.afunc();
	T1.bfunc();
	T1.cfunc();

	T2.afunc();
	T2.bfunc();
	T2.cfunc();

	return 0;
}
