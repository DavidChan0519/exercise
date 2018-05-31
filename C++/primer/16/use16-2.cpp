#include <iostream>
#include <string>
#include <cctype>
#include <vector>
bool isPal(const std::string &s);
std::string process(const std::string &s);
int main()
{
	using namespace std;
	string input;
	cout<<"Enter a string (empty string to quit): \n";
	getline(cin,input);
	while(cin && input.size()>0)
	{
		string temp;
		temp=process(input);
		if(isPal(temp))
		{
			cout<<"That was a palindrome!\n";
		}
		else
			cout<<"That was not a palindrome!\n";
		cout<<"Enter a string (empty string to quit): \n";
		getline(cin,input);
	}
	cout<<"Bye!\n";
	return 0;
}

bool isPal(const std::string &s)
{
	std::string rev(s.rbegin(),s.rend());
	return (rev==s);
}

std::string  process(const std::string &s)
{
	using std::string;
	using std::vector;
	char ch;
	string temp;
	for(unsigned int i=0;i<s.size();i++)
	{
		ch=s[i];
		if(isalpha(ch))
		{
			ch=tolower(ch);
			temp.insert(temp.end(),ch);
		}
	}
	std::cout<<"The processed string: \n";
	std::cout<<temp<<std::endl;
	return temp;
}