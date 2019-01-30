#include <stdio.h>
#define N 10
#define M 15
#include "mas2.h"

void main(void)
{
 int s[N][M];
 float d[N];

 sluch(s, N, M);
 printf("Массив\n");
 vov(s, N, M);
 printf("\n");
 sred(s, d, N, M);
 printf("Массив средних\n");
 vov2(d, N);
 printf("\n");
 printf("номер наименьшего в массиве средних %i\n", mini(d, N));
}


