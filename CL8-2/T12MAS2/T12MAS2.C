#include <stdio.h>
#define N 10
#define M 15
#include "mas2.h"

void main(void)
{
 int s[N][M];
 float d[N];

 sluch(s, N, M);
 printf("���ᨢ\n");
 vov(s, N, M);
 printf("\n");
 sred(s, d, N, M);
 printf("���ᨢ �।���\n");
 vov2(d, N);
 printf("\n");
 printf("����� �������襣� � ���ᨢ� �।��� %i\n", mini(d, N));
}


