#include <stdio.h>
#include <conio.h>

void main( void )
{
  int n, a, i;
  long sum = 0, prod = 1;

  printf("Input amount of numbers: ");
  scanf("%d", &n);
  for(i = 1; i <= n; i++)
  {
    printf("Input a number\n");
    scanf("%d", &a);
    sum = sum + a;
    prod = prod * a;
  }
  printf("Sum is %ld\n", sum);
  printf("Product is %ld\n", prod);
}