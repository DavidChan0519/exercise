#include <iostream>
#include <string>
using namespace std;

class T
{
private:
	int a;

public:
	T()
	{
		cout <<"no parameter"<<endl;
	}

	T(int b):a(b)
	{
		cout << "a=" <<b <<endl;
	}
	void show();	

};


void T::show()
{
	using std::cerr;
	cerr << "hello world"<<endl;
}


int main()
{
	T t1;
	T t2(10);
	t1.show();
	string A1;

	getline(cin , A1);
	cout << A1 << endl;
	return 0;

}
