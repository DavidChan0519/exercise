#include <iostream>
#include <string>

const int SIZE=20;
int main(void)
{
	using namespace std;
	
	string firstname;
	string lastname;
	string fullname;
	cout << "Enter your first name: ";
    cin >> firstname;   
    cout << "Enter your last name: ";
    cin >> lastname;   
    fullname=lastname+','+firstname;
    cout << "Here's the information in a single string: "
         << fullname << endl;
    return 0; 
}