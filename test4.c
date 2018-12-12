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
  / * down is insert and print for ptr */
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
  
/ * down is insert and print for arr and ptr2 */
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
