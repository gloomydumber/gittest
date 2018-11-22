#include <stdio.h>

int main(void)
{
	int a[10]={};
	int arr[5][5]={};
	int i,j;
	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
			printf("%d ",arr[i][j]);
		printf("\n");
	}
	for(i=0;i<10;i++)
		printf("%d ",a[i]);
	return 0;
}
