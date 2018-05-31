#include <iostream>
#include <string>
#include <map>

using namespace std;


int main()
{
	map<int, string> test1 = {{1,"hello"},{2,"world"}};
	test1[3]="love";

	cout << "1:"<<test1.at(1)<<endl;
	cout << "2:"<<test1.at(2)<<endl;
	cout << "3:"<<test1.at(3)<<endl;
	
	for (auto x: test1) {
		cout << x.first << x.second << endl;
	}
	return 0;
}
