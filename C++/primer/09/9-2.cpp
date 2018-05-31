// static.cpp -- using a static local variable
#include <iostream>
#include <string>
#include <cctype>
// constants
const int ArSize = 10;

// function prototype
void strcount(const std::string str);

int main()
{
    using namespace std;
    //char input[ArSize];
	string input;
    //char next;

    cout << "Enter a line:\n";
    getline(cin,input);
    while (cin)
    {
        strcount(input);
        cout << "Enter next line (empty line to quit):\n";
		getline(cin,input);
		if(input=="")
			break;
	}
    cout << "Bye\n";
    return 0;
}

void strcount(const std::string str)
{
	using namespace std;
    static int total = 0;        // static local variable
    int count = 0;               // automatic local variable

    cout << "\"" << str <<"\" contains ";
    size_t size;
	size=str.length();
	for(size_t i=0;i<size;i++)
	{
		if(str[i]==' ')
			continue;
		else if
			(str[i]=='\n')
			continue;
		else
			count++;
	};
	total+=count;
    cout << count << " characters\n";
    cout << total << " characters total\n";
}
