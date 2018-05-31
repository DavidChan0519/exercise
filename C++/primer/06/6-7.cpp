#include <iostream>
#include <string>

using namespace std;


int main()
{
	string words;
	char ch;
	int vowels=0,consonants=0,other=0;
	cout<<"Enter words (q to quit):\n";
	while(cin>>words && words!="q")
	{
		ch=tolower(words[0]);
		if(isalpha(ch))
		{
			if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u')
				vowels++;
			else
				consonants++;
		}else
			other++;
	}
	cout<<vowels<<" words beginning with vowels\n"
	<<consonants<<" words beginning with consonants\n"
	<<other<<" other\n";
	return 0;
}
