#include <stdio.h>
int sd(int a)
{
int s1=0, s2=0;
while(a>0)
    {
     if((a%10)%2!=0)
         s2=s2+(a%10);
     else
         s1=s1+(a%10);
     a=a/10;
    }
if(s1>s2)
    return 1;
else
    if(s1==s2)
        return 2;
    else
        if(s1<s2)
            return 3;
}

void main(void)
{
int a, b;
printf("Введите число\n");
scanf("%d", &a);
b=sd(a);
if(b==1)
    printf("В числе %d сумма четных цифр > суммы нечетных цифр\n", a);
else
    if(b==2)
        printf("В числе %d сумма четных цифр = сумме нечетных цифр\n", a);
    else
        if(b==3)
            printf("В числе %d сумма четных цифр < суммы нечетных цифр\n", a);
}