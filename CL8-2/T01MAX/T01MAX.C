#include <stdio.h>

float max( float a, float b )
{
  if (a > b)
    return a;
  return b;
}

void main( void )
{
  float a, b, c;
  
  printf("Input numbers\n");
  scanf("%f%f%f", &a, &b, &c);
  printf("Highest number is %f\n", max(max(a,b),c));
}