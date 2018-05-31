#include <iostream>
#include "11-6.h"

using namespace std;
int main()
{
	cStonewt compare(11,0);
	cStonewt cmax,cmin;
	int equa=0;
	cStonewt sw[6]={
		cStonewt(7),
		cStonewt(8.2),
		cStonewt(2,8)
	};
	for(int i=0;i<3;i++)
	{
		cin>>sw[i];
	}
	
	for(int i=0;i<6;i++)
	{
		if(cmax<sw[i])
			cmax=sw[i];
		if(cmin>sw[i])
		{
			cmin=sw[i];
		}
		if(compare==sw[i])
			equa++;
		else if(compare>sw[i])
			equa++;
	}
	cout<<"Max:\n"
		<<cmax<<endl;
	cout<<"Min:\n"
		<<cmin<<endl;
	cout<<"the number equation 11 pound is:\n"
		<<equa;
	return 0;
}
