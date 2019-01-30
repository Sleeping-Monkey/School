#include <stdio.h>
#include <stdlib.h>
void sluch(int (*a)[15], int x, int y)
{
 int i, j;

 for(i=0;i<x;i++)
    for(j=0;j<y;j++)
       a[i][j]=rand()%100;
}

void vov(int (*a)[15], int x, int y)
{
 int i, j;

 for(i=0;i<x;i++)
    {
     for(j=0;j<y;j++)
        printf("%i ", a[i][j]);
     printf("\n");
    }
}

void vov2(float *b, int y)
{
 int j;

 for(j=0;j<y;j++)
    printf("%.3f ", b[j]);
}

void sred(int (*a)[15], float *b, int x, int y)
{
 int i, j, sum=0;

 for(i=0;i<x;i++)
   {
    for(j=0;j<y;j++)
       sum+=a[i][j];
    b[i]=sum/y;
    sum=0;
   }
}

int mini(float *b, int y)
{
 int i, j=0, min=b[0];

 for(i=0;i<y;i++)
    if(min>b[i])
     {
      min=b[i];
      j=i;
     }
return j;
}