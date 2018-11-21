// 바둑판 배열에 채워넣기

//Listing 10.20
// matrix
#include <stdio.h>
#include <stdlib.h>

#define ROWS 10
#define COLS 10

void random_walk(int(*a)[COLS], int rows);
void show(int *a, int rows, int cols);

int main(void)
{
	int A[ROWS][COLS];

	random_walk(A, ROWS); ///

	printf("Matrix A:");
	show((int *)A, ROWS, COLS);

	system("pause");
	return 0;
}

void random_walk(int(*a)[COLS], int rows) /// this function assign values to 2d array
{
	for (int r = 0; r < rows; r++)
		for (int c = 0; c < COLS; c++)
			a[r][c] = rand() % 1000;			//// assign any random number between 0 and 1000 using rand() function
}

void show(int *a, int rows, int cols) //// this function shows all the elements in a 2d Array
{

	printf("\n{");
	int i, j;
	for (i = 0; i < rows; i++)
	{
		printf("\n  {");
		for (j = 0; j < cols; j++)
		{
			printf("%d ,", *((a + i*cols) + j));
		}
		printf("} ,");
	}

	printf("\n}\n");
}
// test
