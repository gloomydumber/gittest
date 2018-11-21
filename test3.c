#include <stdio.h> // version for C89 available.
#include <stdlib.h> // for rand() function
#define COLS 10
#define ROWS 10

// void setsize(int *x); C89 setting size of array isn't possible in C89 Standards(C99 available)
void alloc(int rows, int (*arr)[COLS]);
void alloc2(int rows, int(*arr)[COLS]); // 미리 zero chekcing 하는 fucntion
void printarr(int rows, int (*arr)[COLS]);
void checking(int rows, int (*arr)[COLS]);
int findmax(int rows, int (*arr)[COLS]);
int findmin(int rows, int (*arr)[COLS]);

int main(void)
{
	// int x;
	int max, min;
	// setsize(&x);
	int arr[ROWS][COLS];
	// alloc(ROWS,arr);
  alloc2(ROWS,arr);
	// printarr(ROWS,arr);
	checking(ROWS,arr);
	printarr(ROWS,arr);
	max=findmax(ROWS,arr);
	min=findmin(ROWS,arr);
	printf("max : %2d\nmin : %2d\n",max,min);
}
/*
void setsize(int *x)
{
	printf("type x : ");
	scanf("%d",x);
}
*/
void alloc(int rows,int (*arr)[COLS]) // 0부터 100미만으로 할당하는 함수
{
	int i=0, j=0;
	for(i=0;i<rows;i++)
		for(j=0;j<COLS;j++)
			arr[i][j]=rand()%100;
}

void alloc2(int rows, int(*arr)[COLS]) // 애초에 0 아닌걸 할당하는 함수
{
  int i=0, j=0;
  int temp;
  for(i=0;i<rows;i++)
    {
      for(j=0;j<COLS;j++)
        {
          temp=rand()%100;
          while(temp==0)
            temp=rand()%100;
          arr[i][j]=temp;
        }
    }
}

void printarr(int rows,int (*arr)[COLS]) // 출력 함수
{
	for(int i=0;i<rows;i++)
	{
		printf("{ ");
		for(int j=0;j<COLS;j++)
		{
			printf("%2d ",arr[i][j]);
		}
		printf("}");
		printf("\n");
	}
}

void checking(int rows,int (*arr)[COLS]) // 0 인놈 적발해서 0아닌거 할당하는 함수
{
	int i,j;
		for(i=0;i<rows;i++)
		{
			for(j=0;j<COLS;j++)
			{
				while(arr[i][j]==0)
				{
					arr[i][j]=rand()%100;
					printf("zero detreced\n");
				}
			}
		}
}

int findmax(int rows,int (*arr)[COLS]) // 젤큰놈
{
	int temp=0;
	int i=0, j=0;

	for(i=0;i<rows;i++)
		for(j=0;j<COLS;j++)
			temp=temp>arr[i][j] ? temp:arr[i][j];

	return temp;
}

int findmin(int rows,int (*arr)[COLS]) //젤작놈
{
	int temp=100;
	int i=0, j=0;

	for(i=0;i<rows;i++)
		for(j=0;j<COLS;j++)
			temp=temp<arr[i][j] ? temp:arr[i][j];

	return temp;
}
