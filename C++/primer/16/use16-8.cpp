#include <iostream>
#include <string>
#include <set>
#include <algorithm>


int main()
{
	using namespace std;
	string temp;
	set<string>mats;
	cout << "Enter Mat's guest list (empty line to quit):\n";
	while(getline(cin,temp) && temp.size()>0)
	{
		mats.insert(temp);
	}
	std::ostream_iterator<string,char>out_iter(cout,"\n");
	cout<<"Mat's guest list:\n";
	copy(mats.begin(),mats.end(),out_iter);

	set<string>pats;
	cout<<"Enter Pat's guest list (empty line to quit):\n";
	while(getline(cin,temp) && temp.size()>0)
	{
		pats.insert(temp);
	}
	copy(pats.begin(),pats.end(),out_iter);
	
	set<string>both;
	
	std::set_union(mats.begin(),mats.end(),pats.begin(),pats.end(),std::insert_iterator<set<string>>(both,both.begin()));
	cout<<"\nMegerd guest list:\n";
	copy(both.begin(),both.end(),out_iter);
	return 0;
}

