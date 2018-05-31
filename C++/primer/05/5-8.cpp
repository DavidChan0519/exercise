#include <iostream>
#include <string>
using namespace std;


int main()
{
	int count=0;
	string word;
	cout<<"Enter words(to stop,type the word \"done\"):\n";
	while(cin>>word && word!="done")//相等返回0，则while（0）跳出
		count++;
	cout<<"your entered a total of "<<count<<" words."<<endl;
	return 0;
}