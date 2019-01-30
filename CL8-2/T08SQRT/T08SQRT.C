#include <stdio.h>
#include <math.h>
#define EPS 1E-8
double St(double a)
{double Y0=a, Y1;
Y1=Y0+(a/Y0-Y0)/2;
while(Y1-Y0>EPS || Y1-Y0<-EPS)
    {
     Y0=Y1;
     Y1=Y0+(a/Y0-Y0)/2;
    }
return Y1;
}
void main(void)
{
double x;
printf("Введите число ");
scanf("%lf", &x);
printf("Число, полученое моей функцией %lf\n", St(x));
printf("Число, полученое фукцией sqrt %lf\n", sqrt(x));
}












