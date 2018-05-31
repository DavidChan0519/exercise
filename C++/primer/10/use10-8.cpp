#include <iostream>
#include "10-8.h"

using namespace std;

void showmovies(Item it);
int main()
{
	cList movies;
	Item temp;
	if(movies.isfull())
	{
		cout<<"no more room in list!Bye!\n";
		exit(1);
	}
	cout<<"enter fist movie title:\n";
	while(cin.getline(temp.title,SIZE) && temp.title[0]!='\0')
	{
		cout<<"Enter your rating <0-10>:";
		cin>>temp.rating;
		while(cin.get()!='\n')
			continue;
		if(movies.additem(temp)==false)
		{
			cout<<"List already full!\n";
			break;
		}
		if(movies.isfull())
		{
			cout<<"you have filled the list.\n";
			break;
		}
		cout<<"Enter next movie title(empty line to stop):\n";
	}
	if(movies.isempty())
	{
		cout<<"No data entered.";
	}
	else
	{
		cout<<"here is the movie list:\n";
		movies.transverse(showmovies);
	}
	cout<<"Bye!\n";
	return 0;
}

void showmovies(Item it)
{
	cout<<"Movie:"<<it.title<<"  Rating:"<<it.rating<<endl;
}