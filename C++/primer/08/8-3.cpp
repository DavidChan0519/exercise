#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

void mytoupper(std::string &a)
{
	using std::cout;
	size_t size;
	size=a.size();
	for(size_t i=0;i<size;i++)
		cout.put(toupper(a[i]));
}

int main()
{
	std::string name="abah W 2278 ie8";
	mytoupper(name);
	return 0;
}

