#include <iostream>
using namespace std;

const int Len=66;
const int Divs=6;

void subdivide(char ar[],int low,int hight,int level)
{
	if(level==0)
		return;
	int mid;
	mid=(low+hight)/2;
	ar[mid]='|';
	subdivide(ar,low,mid,level-1);
	subdivide(ar,mid,hight,level-1);
}

int main()
{
	char ruler[Len];
	for(int i=1;i<Len-2;i++)
		ruler[i]=' ';
	ruler[Len-1]='\0';
	int max=Len-2;
	int min=0;
	ruler[min]=ruler[max]='|';
	cout<<ruler<<endl;
	for(int i=0;i<Divs;i++)
	{
		subdivide(ruler,min,max,i);
		cout<<ruler<<endl;
	}
	return 0;
}


