#include <stdio.h>

int main()
{
	float n = 0.0;
	float i =990.300001;
	float j = 6.666666;
	float k = i+j;
	float *m= NULL;

	char *pc = (char *)(&k);
	char val[4]={0};


	val[0]=*pc;
	printf("reulst = %02x\n",*pc);
	
	val[0]=0xde;
		
	val[1]=*(pc+1);
	printf("reulst = %02x\n",*(pc+1));
	
	val[2]=*(pc+2);
	printf("reulst = %02x\n",*(pc+2));

	val[3]=*(pc+3);
	printf("reulst = %02x\n",*(pc+3));
	
	m = (float *)val;	
	
	printf("++ m= %f\n",*m);
	return 0;

}
