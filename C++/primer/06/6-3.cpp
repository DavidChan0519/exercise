#include <iostream>
#include <string>

int main()
{
	using namespace std;
	string item[4]={"c) carnivore","p) pianist",
		"t) tree ","g) game"};
	char input;
	while(cout<<"Please enter a c,p,t,or g:"&&cin>>input)
	{
		switch(input)
		{
		case 'a':
			cout<<item[0]<<endl;
			break;
		case 'c':
			cout<<item[1]<<endl;
			break;
		case 'p':
			cout<<item[2]<<endl;
			break;
		case 't':
			cout<<item[3]<<endl;
			break;
		case 'g':
			cout<<item[3]<<endl;
			break;
		default:
			//cout<<"Please enter a c,p,t,or g:";
		}
	}
	return 0;
}