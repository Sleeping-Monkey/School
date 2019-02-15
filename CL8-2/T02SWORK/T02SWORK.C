#include <stdio.h>

int sum( int t )
{
  int sum1 = 0, i;
  for (i = 1; i < t; i++)
    if (t % i == 0)
      sum1 = sum1 + i;
  return sum1;
}

void main (void)
{
  int a, i;
  
  printf("Input a number\n");
  scanf("%d", &a);
  if (a == sum(a))
    printf("Число %d совершенное\n", a);
  else
    printf("Число %d не совершенное\n", a);
}
