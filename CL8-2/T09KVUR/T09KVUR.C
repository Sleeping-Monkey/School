#include <stdio.h>
#include <math.h>

void ur( double a, double b, double c )
{
  double d = 0;
  if (a == 0)
    if (b == 0)
      if (c == 0)
        printf("X is any number\n");
      else
        printf("No solutions\n");
    else
      printf("X = %.10lf\n", -(c / b));
  else
    if (b * b - 4 * c * a < 0)
    {
      d = sqrt(4 * a * c - b * b);
      printf("X1 = %.10lf + i%.10lf\n X2 = %.10lf - i%.10lf\n", b / 2 / a, d / 2 / a, b / 2 / a, d / 2 / a);
    }
    else
      if (b * b - 4 * c * a == 0)
        printf("X = %.10lf\n", b / 2 / a);
      else
      {
        d = sqrt(b * b - 4 * a * c);
        printf("X1 = %.10lf\n X2 = %.10lf\n", (d - b) / 2 / a, -(d + b) / 2 / a);
      }
}

void main( void )
{
  double an, bn, cn;
  printf("Input a, b, c\n");
  scanf("%lf%lf%lf", &an, &bn, &cn);
  ur(an, bn, cn);
}