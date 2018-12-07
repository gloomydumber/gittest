#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 3

struct students{
  int snumber;
  char *name[30];
  char *addr[30];
  int age;
  float score;
};

void getinfo(struct students *st, int n);
void printinfo(struct students *st, int n);

int main(void)
{
  int n =N;
  struct students st[N];
  getinfo(st, n);
  printinfo(st, n);
  return 0;
}

void getinfo(struct students *st, int n)
{
  int i;
  for(i=0;i<N;i++)
  {
    printf("type %d's student number : ",i+1);
    scanf("%d",&st[i].snumber);
    printf("type %d's student name : ",i+1);
    scanf("%s",*(*st[i].name));
    printf("type %d's student addr : ",i+1);
    scanf("%s",*(*st[i].addr));
    printf("type %d's studnet age : ",i+1);
    scanf("%d",&st[i].age);
    printf("type %d's student score : ",i+1);
    scanf("%f",&st[i].score);
  }
}

void printinfo(struct students *st, int n)
{
  int i;
  for(i=0;i<N;i++)
  {
    printf("%d's student number : %d\n",i+1,st[i].snumber);
    printf("%d's student name : %s\n",i+1,st[i].name);
    printf("%d's student addr : %s\n",i+1,st[i].addr);
    printf("%d's studnet age : %d\n",i+1,st[i].age);
    printf("%d's student score : %f\n",i+1,st[i].score);
  }
}
// 평균나이
// 평균학점
