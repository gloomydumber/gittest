//학번: 201661701
//이름: 강동민
//Name(English): KANG DONGMIN (githubid : gloomydumber)
/* 다음 프로그램을 수정한다.
1.	Random_walk()등의 호출 함수 body에서는 a[][][] 형태를 사용 금지, 대신에 *a 등의 표기 사용, 다른 pointer  변수 사용 가능함
2.	행렬 초기화후에 randonwalk()를 2회 이상 호출시에 cell이 0 이상이면 “Already Done” 메시지를 내보냄, 초기화 함수를 호출한 후에 다시 실행 가능함  */
// matrix ~ 11:45am description 학번
#include <stdio.h>
#include <stdlib.h>

#define ROWS 20
#define COLS 30
#define HIGH 10

void initializeMatrix(int(*a)[COLS][ROWS], int high); //모든 원소를 0으로 초기화
void randomWalk(int(*a)[COLS][ROWS], int high);

int findMAX(int(*a)[COLS][ROWS], int high);
float getAverage(int(*a)[COLS][ROWS], int high);
void showMatrix(int (*a)[COLS][ROWS], int high, int cols, int rows);

int main(void)
{
	int A[HIGH][COLS][ROWS];
	int select, n;
	float average;
	while (1)
	{
		printf("\nSelect command 1: 행렬 초기화, 2: random walk,  3: find MAX, 4: get Average, 5. Display, 6: Quit => ");
		scanf("%d", &select);
		switch (select)
		{
		case 1:
			initializeMatrix(A, HIGH);
			break;

		case 2:
			randomWalk(A, HIGH);
			break;

		case 3:
			n = findMAX(A, HIGH);
			printf("MAX = %d\n", n);
			break;
		case 4:
			average = getAverage(A, HIGH);
			printf("%.2f", average); //소수점 두자리까지 출력
			break;
		case 5:
			showMatrix(A, HIGH, COLS, ROWS);
			break;
		default:
			exit(0);
			break;
		}
	}
	system("pause");
	return 0;
}
void initializeMatrix(int(*a)[COLS][ROWS], int high)
//모든 원소를 0으로 초기화
{
	int i, j, k;
	for (i = 0; i < high; i++)
		for (j = 0; j < COLS; j++)
			for (k = 0; k < ROWS; k++)
				*(*(*(a+i)+j)+k) = 0;
}

void randomWalk(int(*a)[COLS][ROWS], int high)
{
  int i, j, k;

  /* it's for randomize moth code. but it's too big to allocate [10][30][20] size array.
    // (1st way)
    int index=0;
    while(index<high*COLS*ROWS)
    {
    index=0;
		i = rand() % 10;
		j = rand() % 30;
		k = rand() % 20;
    if(*(*(*(a+i)+j)+k)==0)
    {
      *(*(*(a+i)+j)+k) = (rand()%99)+1; // 100미만 0초과의 랜덤 수 배정
      index++;
    }
    */

    // (2nd way : more faster than 1st way)
    int index=0;
    int compare[10][30][20]={};
    while(index<high*COLS*ROWS)
    {
      index=0;
      i = rand() % 10;
      j = rand() % 30;
      k = rand() % 20;
      if(*(*(*(a+i)+j)+k)==0)
      {
        *(*(*(a+i)+j)+k) = (rand()%99)+1; // 100미만 0초과의 랜덤 수 배정
      }
      for(i=0;i<high;i++)
      {
    		for(j=0;j<COLS;j++)
        {
    			for(k=0;k<ROWS;k++)
          {
    				if(*(*(*(a+i)+j)+k)!=*(*(*(compare+i)+j)+k))
            {
              index++;
            }
            }
        }
      }
    }


/*
    for(i=0;i<high;i++) //this is just allocate by using for loop. (not moth randomize)
      for(j=0;j<COLS;j++) // occur memory problem -> use this code.
        for(k=0;k<ROWS;k++)
          *(*(*(a+i)+j)+k) = (rand()%99)+1;
*/
	//모든 cell이 0 이상일 때 종료
	//나방이 임의 장소 a[i][j][k] 선택은 I, j, k는 난수를 만들어 결정
	// 배열 a[][][] 방식 사용 금지, 대신에 *만 사용
}

int findMAX(int(*a)[COLS][ROWS], int high)
{
	int max=0;
	int i, j, k;
	for(i=0;i<high;i++)
		for(j=0;j<COLS;j++)
			for(k=0;k<ROWS;k++)
				max=(max>*(*(*(a+i)+j)+k))?max:*(*(*(a+i)+j)+k);
				//최대값을 return
				// 배열 a[][][] 방식 사용 금지, 대신에 *만 사용
	return max;
}

float getAverage(int(*a)[COLS][ROWS], int high)
{
	float avg;
	int total=0;
	int i, j, k;
	for (i = 0; i < high; i++)
		for (j = 0; j < COLS; j++)
			for (k = 0; k < ROWS; k++)
				total += *(*(*(a+i)+j)+k);
	avg = (float)total / (float)(high*COLS*ROWS);
	return avg;

	//모든 cell의 평균값을 구한다
	// 배열 a[][][] 방식 사용 금지, 대신에 *만 사용

}

void showMatrix(int (*a)[COLS][ROWS], int high, int cols, int rows)
{
	int i, j, k;
	for(i=0;i<high;i++)
	{
		printf("high[%d] :\n",i);
		for(j=0;j<cols;j++)
			{
			printf("{ ");
				for(k=0;k<rows;k++)
					{
					printf("%2d ",*(*(*(a+i)+j)+k));
					}
				printf("} \n");
			}
		printf("\n");
	}


	// high[0]에 대하여 2차원 배열 값 출력, high[1]에 대하여 2차원 배열 값 출력 등으로 처리
	// 배열 a[][][] 방식 사용 금지, 대신에 *만 사용

}
