#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct man{
  int age;
  char name[20];
  char job[20];
};

int main(void)
{
 struct man them[2];
 struct man *simple;
 simple=&them[0];
 int i;
 for(i=0;i<2;i++)
 {
   printf("type age for %d's man : ",i+1);
   scanf("%d",&them[i].age);
   printf("type age for %d's name : ",i+1);
   scanf("%s",them[i].name);
   printf("type age for %d's job : ",i+1);
   scanf("%s",them[i].job);
 }
 for(i=0;i<2;i++)
 {
   printf("age for %d's man : %d\n",i+1,(simple+i)->age);
   printf("age for %d's man : %s\n",i+1,(simple+i)->name);
   printf("age for %d's man : %s\n",i+1,(simple+i)->job);
 }

 return 0;
}
