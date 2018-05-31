#include <iostream>
#include <cstring>//include strcmp()
using namespace std;


int main()
{
	int count=0;
	char word[20];
	cout<<"Enter words(to stop,type the word \"done\"):\n";
	while(cin>>word && strcmp("done",word))//相等返回0，则while（0）跳出
		count++;
	cout<<"your entered a total of "<<count<<"words."<<endl;
	return 0;
}