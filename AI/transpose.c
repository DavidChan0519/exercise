#include <stdio.h>

int main()
{
	int a[4][3]={{1,2,3},{4,5,6},{7,8,9},{10,11,12}};
	int b[3][4]={0};
	for (int i=0; i<4; i++) {
		for (int j=0; j<3; j++) {
			b[j][i]=a[i][j];
			printf("%02d ",a[i][j]);
		}
		printf("\n");
	}

	printf("==================================\n");

	for (int i=0; i<3;i++) {
                for (int j=0; j<4; j++) {
                        printf("%02d ",b[i][j]);
                }
                printf("\n");
        }


}
