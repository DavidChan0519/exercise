#include <iostream>
using namespace std;

int main(void)
{
	char firstname[20],lastname[20],letter,grade;
	unsigned int age;
	cout<<"What is your first name?";
	cin>>firstname;
	cout<<"What is your last name?";
	cin>>lastname;
	cout<<"What letter grade do you deserve?";
	cin>>letter;
	cout<<"What is your age?";
	cin>>age;
	grade=letter+1;
	cout<<"Name:"<<lastname<<","<<firstname<<endl;
	cout<<"Grade:"<<grade<<endl;
	cout<<"Age:"<<age<<endl;
	return 0;
}
