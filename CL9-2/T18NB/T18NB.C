#include "nb.h"

void main(void)
{
int flag=1, i, DBSize=0;
PUPIL DB[MAX];
char S[15];
FILE *f;
while(flag)
{printf("0 - ��室\n1 - ����������\n2 - �뢮� ���\n3 - �������� �� ������\n4 - ���஢��\n     a - �� ��䠢���\n     b - �� ��� ஦�����\n5 - ��ॢ��� ����\n6 - ���࠭����� 䠩��\n7 - ����㧪� 䠩��\n");
switch(getch())
{
case '0':
    flag=0;
    break;
case '1':
     if(DBSize<MAX)
     ReadPupil(&DB[DBSize++]);
     else
     printf("\n!!!������������!!!\n");
     break;
case '2':
     for(i=0;i<DBSize;i++)
     {
     printf("%02i %s   %s   %02i.%02i.%04i %c %02d-%d %s\n",++i,DB[i].Surname,DB[i].Name,DB[i].Birthday,DB[i].Sex,DB[i].Form,DB[i].FormDigit,DB[i].Phone);
     i--;
     }
     printf("�ᥣ� � ��襩 ���� %i 祫����\n", DBSize);
     break;
case '3':
     printf("������ �����: ");
     scanf("%i", &i);
     i--;
     if(i>=0 && i<DBSize)
       for(;i<=DBSize-1;i++)
             DB[i]=DB[i+1];
       DBSize--;
       printf("OK\n");
       GetStr(NULL, 0);
     break;
case '4':
     printf("a ��� b?\n");
     switch(getch())
     {
     case 'a':
     SortSurname(&DB,DBSize);
     printf("OK\n");
     break;
     case 'b':
     SortDate(&DB,DBSize);
     printf("OK\n");
     break;
     default:
     printf("������ ����⢨� ����������\n");
     break;
     }
     break;
case '5':
     for(i=0;i<DBSize/2;i++)
     pswap(&DB[i],&DB[DBSize - i - 1]);
     break;
case '6':
    printf("�������� �����:\n");
    GetStr(S,15);
    f=fopen(S,"wb");
    fwrite(DB,sizeof(DB[0]),DBSize, f);
    fclose(f);
    break;
    case '7':
    printf("������ �������� �����:\n");
    GetStr(S,15);
    DBSize=LoadDB(S,DB,MAX);
    printf("OK\n");
    fclose(f);
    break;
default:
printf("������ ����⢨� ����������\n");
break;
}
}
}