#include <stdio.h>
#include <stdlib.h>
#define ROWS 10
#define COLS 10

void printarr(int (*arr)[COLS],int rows);
void randalloc(int (*arr)[COLS],int rows);

int main(void)
{
	int arr[ROWS][COLS]={};
	printarr(arr,ROWS);
	randalloc(arr,ROWS);
	printarr(arr,ROWS);
	return 0;
}

void printarr(int (*arr)[COLS],int rows)
{
	int i,j;
	for(i=0;i<rows;i++)
	{
		for(j=0;j<COLS;j++)
			printf("%2d ",arr[i][j]);
		printf("\n");
	}
}

void randalloc(int (*arr)[COLS],int rows)
{
  int i,j;
  i=rand()%11;
  j=rand()%11;
	while(arr[i][j]==0)
  {
    arr[i][j]=rand()%100;
    i=rand()%11;
    j=rand()%11;
  }
}
