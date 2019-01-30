#include <stdio.h>
int Day(int D, int M, int Y)
{int N;
if(M>2)
    M++;
else
   {
    M+=13;
    Y--;
   }
N=(int)((Y*36525L/100+M*306/10+D-621050L)%7);
return N;
}
void main(void)
{int D, M, Y, N;
printf("Введите день ");
scanf("%d", &D);
printf("Введите месяц ");
scanf("%d", &M);
printf("Введите год ");
scanf("%d", &Y);
N=Day(D, M, Y);
if(N==0)
    printf("День %d,%d,%d - понедельник", D, M, Y);
else
    if(N==1)
        printf("День %d,%d,%d - вторник", D, M, Y);
    else
        if(N==2)
            printf("День %d,%d,%d - среда", D, M, Y);
        else
            if(N==3)
                printf("День %d,%d,%d - четверг", D, M, Y);
            else
                if(N==4)
                    printf("День %d,%d,%d - пятница", D, M, Y);
                else
                    if(N==5)
                        printf("День %d,%d,%d - суббота", D, M, Y);
                    else
                        if(N==6)
                        printf("День %d,%d,%d - воскресенье", D, M, Y);

}