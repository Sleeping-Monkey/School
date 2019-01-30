#include <stdio.h>
void main(void)
{float a, b;
printf("Введите числа a и b для уравнения ax+b=0\n");
printf("a=");
scanf("%f", &a);
printf("b=");
scanf("%f", &b);
b=-b;
if(a==0 && b==0)
printf("x - Любое число\n");
if(a==0 && b!=0)
printf("Нет корней\n");
if(a!=0 && b==0)
printf("x=0\n");
if(a!=0 && b!=0)
printf("x=%f\n",b/a);
}