#include <stdio.h> // version for VLA(Variable-Length-Array) C99 Standards.. not for visual studio(c89)
#include <stdlib.h> // for rand() function

void setsize(int *x, int *y);
void alloc(int x, int y, int (*arr)[y]);
void printarr(int x,int y,int (*arr)[y]);
void checking(int x,int y,int (*arr)[y]);
int findmax(int x,int y,int (*arr)[y]);
int findmin(int x,int y,int (*arr)[y]);

int main(void)
{
	int x; int y;
	int max, min;
	setsize(&x,&y);
	int arr[x][y];
	alloc(x,y,arr);
	printarr(x,y,arr);
	checking(x,y,arr);
	printarr(x,y,arr);
	max=findmax(x,y,arr);
	min=findmin(x,y,arr);
	printf("max : %2d\nmin : %2d\n",max,min);
}

void setsize(int *x, int *y)
{
	printf("type x : ");
	scanf("%d",x);
	printf("type y : ");
	scanf("%d",y);
}

void alloc(int x,int y,int (*arr)[y])
{
	int i=0, j=0;
	for(i=0;i<x;i++)
		for(j=0;j<y;j++)
			arr[i][j]=rand()%100;
}

void printarr(int x,int y,int (*arr)[y])
{
	for(int i=0;i<x;i++)
	{
		printf("{ ");
		for(int j=0;j<y;j++)
		{
			printf("%2d ",arr[i][j]);
		}
		printf("}");
		printf("\n");
	}
}
void checking(int x,int y,int (*arr)[y])
{
	int i,j;
		for(i=0;i<x;i++)
		{
			for(j=0;j<y;j++)
			{
				while(arr[i][j]==0)
				{
					arr[i][j]=rand()%100;
					printf("zero detreced\n");
				}
			}
		}
}

int findmax(int x,int y,int (*arr)[y])
{
	int temp=0;
	int i=0, j=0;

	for(i=0;i<x;i++)
		for(j=0;j<y;j++)
			temp=temp>arr[i][j] ? temp:arr[i][j];

	return temp;
}

int findmin(int x,int y,int (*arr)[y])
{
	int temp=100;
	int i=0, j=0;

	for(i=0;i<x;i++)
		for(j=0;j<y;j++)
			temp=temp<arr[i][j] ? temp:arr[i][j];

	return temp;
}
