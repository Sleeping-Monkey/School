#include <stdio.h>
int dv(int a)
{int b, c;
if(a==0)
return 0;
b=a%10;
c=(a/10)%10;
if(b==c)
return 1;
else
return 0;
}
void main(void)
{int n, a, i;
 printf("Введите количество чисел\n");
 scanf("%d", &n);
 printf("Введите числа через пробел\n");
for(i=1;i<=n;i++)
{
    scanf("%d", &a);
 if(dv(a)==1)
    printf("%d\n",a);
}
}