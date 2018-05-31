#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <fstream>
using namespace std;

void showReview(vector<int>&r)
{
	vector<int>::iterator pr;
	for( pr=r.begin();pr!=r.end();pr++)
		cout<<*pr<<" ";
}

std::vector<int>Lotto(int n,int num)
{
	int *ar=new int[n];
	for(int i=0;i<=n;i++)
		ar[i]=i+1;
	
	vector<int>temp(n);
	copy(ar,ar+n,temp.begin());
	std::random_shuffle(temp.begin(),temp.end());
	return temp;
}
int main()
{
	ostream_iterator<int>out_iter(cout," ");
	std::srand(time(0));
	vector<int>winner;
	winner=Lotto(51,6);
	copy(winner.begin(),winner.begin()+6,out_iter);
	
	return 0;
}
