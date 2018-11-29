#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  int i,j; //ptr2와 ptr 비교...
  int h;
  int y;
  int* ptr2=(int*)malloc(sizeof(int));
  printf("type heng : ");
  scanf("%d",&h);
  printf("type yul : ");
  scanf("%d",&y);
  *ptr2=h*y;
  int arr[*ptr2];
  int **ptr=(int**)malloc(sizeof(int*)*h);
  for(i=0;i<h;i++)
  {
    ptr[i]=(int*)malloc(sizeof(int)*y);
  }
  for(i=0;i<h;i++)
  {
    for(j=0;j<y;j++)
    {
      printf(" type ptr[%d][%d] : ",i,j);
      scanf("%d",&ptr[i][j]);
    }
  }
  for(i=0;i<h;i++)
  {
    for(j=0;j<y;j++)
    {
      printf("%d ",*(*(ptr+i)+j));
    }
    printf("\n");
  }

for(i=0;i<(h*y);i++)
{
  printf("type arr[%d]: ",i);
  scanf("%d",&arr[i]);
}
for(i=0;i<h*y;i++)
{
  printf("%d ",arr[i]);
}
// 행바뀔때 젤 처음거
// printf("%d\n",*ptr[0]);
// printf("%d\n",*ptr[1]);
// printf("%d\n",*ptr[2]);

  return 0;
}
/*
3x3

0~8

00-0 01-1 02-2
10-3 11-4 12-5
20-6 21-7 22-8

ix3+j

3x4
0~11
00-0 01-1 02-2 03-3
10-4 11-5 12-6 13-7
20-8 21-9 22-10 23-11
ix4+j 

4x3
0~11
00-0 01-1 02-2
10-3 11-4 12-5
20-6 21-7 22-8
30-9 31-10 32-11

ix3+j



233
18

0~17

[0]
00-0 01-1 02-2
10-3 11-4 12-5
20-6 21-7 22-8
[1]
00-9 01-10 02-11
10-12 11-13 12-14
20-15 21-16 22-17
[2]
00-18 01 02
10 11 12
20 21 22

ix3x3+jx3+k

224
0~15
[0]
00-0 01-1 02-2 03-3
10-4 11-5 12-6 13-7

[1]
00-8 01-9 02-10 03-11
10-12 11-13 12-14 13-15
ix2x4+jx4+k
*/
