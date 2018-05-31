#include <iostream>
#include <string>
using namespace std;

int main()
{
	string ss("12345678");
	string::iterator bt = ss.begin();
	string::iterator et = ss.end();
	cout << "1st: " << *bt << endl;
	cout << "2nd: " << *et << endl;
    string a="abcdefg";
    string b="lmn";
    a=b;
    cout << "a:"<<a<<endl;
    return 0;
}
