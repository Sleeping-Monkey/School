#include <stdio.h>
float max (float a, float b)
{
 if(a>b)
 return a;
 else
 return b;
}
void main(void)
{float a, b, c;
  printf("Введите 3 числа\n");
  scanf("%f%f%f", &a, &b, &c);
  printf("Наибольшее число: %f\n", max(max(a,b),c));
 return 0;
}