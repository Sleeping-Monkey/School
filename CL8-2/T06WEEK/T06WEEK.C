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
printf("������ ���� ");
scanf("%d", &D);
printf("������ ����� ");
scanf("%d", &M);
printf("������ ��� ");
scanf("%d", &Y);
N=Day(D, M, Y);
if(N==0)
    printf("���� %d,%d,%d - �������쭨�", D, M, Y);
else
    if(N==1)
        printf("���� %d,%d,%d - ��୨�", D, M, Y);
    else
        if(N==2)
            printf("���� %d,%d,%d - �।�", D, M, Y);
        else
            if(N==3)
                printf("���� %d,%d,%d - �⢥�", D, M, Y);
            else
                if(N==4)
                    printf("���� %d,%d,%d - ��⭨�", D, M, Y);
                else
                    if(N==5)
                        printf("���� %d,%d,%d - �㡡��", D, M, Y);
                    else
                        if(N==6)
                        printf("���� %d,%d,%d - ����ᥭ�", D, M, Y);

}