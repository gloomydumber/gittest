// i made *** malloc !!!!!!!

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int i,j,k;
	int high;
	int heng;
	int yul;
	
	printf("type high : ");
	scanf("%d",&high);
	printf("type heng : ");
	scanf("%d",&heng);
	printf("type yul : ");
	scanf("%d",&yul);
	
	int ***a=(int***)malloc(sizeof(int**)*high);

	for(i=0;i<high;i++)
	{
		a[i]=(int**)malloc(sizeof(int*)*heng);
	}
	
	for(i=0;i<high;i++)
	{
		for(j=0;j<heng;j++)
		{
		a[i][j]=(int*)malloc(sizeof(int)*yul);
		}

}

for(i=0;i<high;i++)
	{
		for(j=0;j<heng;j++)
		{
			for(k=0;k<yul;k++)
				{
					printf("type a[%d][%d][%d] = ",i,j,k);
					scanf("%d",&*(*(*(a+i)+j)+k));
				}
			}
		}
	
		for(i=0;i<high;i++)
			{
				printf("high %d :\n",i);
				for(j=0;j<heng;j++)
				{
					for(k=0;k<yul;k++)
						{
							printf("%4d",*(*(*(a+i)+j)+k));
						}
						printf("\n");
					}
				}
}
