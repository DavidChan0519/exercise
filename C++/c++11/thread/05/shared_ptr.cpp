#include <iostream>
#include <memory>

using namespace std;

class Test
{
public:
	Test(string s):str(s)
	{
		cout <<"Test new:"<< str << endl;
	}
	
	~Test()
	{
		cout<<"Test delete:"<<str<<endl;
	}
	
	string & getStr()
	{
		return str;
	}
	
	void setStr(string s)
	{
		str = s;
	}

	void print()
	{
		cout << str << endl;
	}

private:
	string str;
};


int main()
{
	shared_ptr<Test> ptest1 = make_shared<Test>("123");
	shared_ptr<Test> ptest2(new Test("456"));

	cout << ptest1->getStr() << endl;
	cout << "ptest 1 use count:" << ptest1.use_count()<<endl;

	cout << ptest2->getStr() << endl;
	cout << "ptest 2 use count:" << ptest2.use_count()<<endl;

	ptest1 = ptest2;
	ptest1->print();
	
	cout<<"after ptest2 use count:"<< ptest2.use_count()<<endl;//2
	cout<<"after ptest1 use count:"<< ptest1.use_count()<<endl;//2

	ptest1.reset();
	cout << "last ptest2 use count:"<< ptest2.use_count()<<endl;
	cout << "============seperate line==========="<< endl;
	ptest2.reset();//此时“456”销毁
	cout<<"done !\n";
	
	return 0;	
}
