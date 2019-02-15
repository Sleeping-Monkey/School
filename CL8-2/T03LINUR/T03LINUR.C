#include <stdio.h>

void main( void )
{
  float a, b;
  printf("Input a number a and b from ax + b = 0\n");
  printf("a = ");
  scanf("%f", &a);
  printf("b = ");
  scanf("%f", &b);
  b = -b;
  if (a == 0 && b == 0)
    printf("x - Any number\n");
  if (a == 0 && b != 0)
    printf("No solutions\n");
  if (a != 0 && b == 0)
    printf("x = 0\n");
  if (a != 0 && b != 0)
    printf("x = %f\n", b / a);
}