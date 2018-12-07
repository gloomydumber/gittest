#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  int i,j;
  int h;
  int y;
  printf("type heng : ");
  scanf("%d",&h);
  printf("type yul : ");
  scanf("%d",&y);
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
 
  return 0;
}
