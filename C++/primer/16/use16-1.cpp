#include <iostream>
#include <string>

bool isPal(const std::string &s);

int main()
{
	using namespace std;
	string input;
	cout<<"Enter a string (empty string to quit): \n";
	getline(cin,input);
	while(cin && input.size()>0)
	{
		if(isPal(input))
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
