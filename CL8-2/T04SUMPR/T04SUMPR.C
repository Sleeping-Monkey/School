#include <stdio.h>
#include <conio.h>
void main(void)
{int n, a, i;
long sum=0, proi=1;
printf("Введите количество чисел");
scanf("%d", &n);
for(i=1;i<=n;i++)
{
printf("Введите число\n");
scanf("%d", &a);
sum=sum+a;
proi=proi*a;
}
printf("Сумма введенных чисел = %ld\n", sum);
printf("Произведение введенных чисел = %ld\n", proi);
 getch();
}