#include "nb.h"

void main(void)
{
int flag=1, i, DBSize=0;
PUPIL DB[MAX];
char S[15];
FILE *f;
while(flag)
{printf("0 - Выход\n1 - Добавление\n2 - Вывод всех\n3 - Удаление по номеру\n4 - сортировка\n     a - По алфавиту\n     b - По дате рождения\n5 - Переворот базы\n6 - Сохраниение файла\n7 - Загрузка файла\n");
switch(getch())
{
case '0':
    flag=0;
    break;
case '1':
     if(DBSize<MAX)
     ReadPupil(&DB[DBSize++]);
     else
     printf("\n!!!ПЕРЕПОЛНЕНИЕ!!!\n");
     break;
case '2':
     for(i=0;i<DBSize;i++)
     {
     printf("%02i %s   %s   %02i.%02i.%04i %c %02d-%d %s\n",++i,DB[i].Surname,DB[i].Name,DB[i].Birthday,DB[i].Sex,DB[i].Form,DB[i].FormDigit,DB[i].Phone);
     i--;
     }
     printf("Всего в вашей базе %i человек\n", DBSize);
     break;
case '3':
     printf("Введите номер: ");
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
     printf("a или b?\n");
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
     printf("Данное действие невозможно\n");
     break;
     }
     break;
case '5':
     for(i=0;i<DBSize/2;i++)
     pswap(&DB[i],&DB[DBSize - i - 1]);
     break;
case '6':
    printf("Название папки:\n");
    GetStr(S,15);
    f=fopen(S,"wb");
    fwrite(DB,sizeof(DB[0]),DBSize, f);
    fclose(f);
    break;
    case '7':
    printf("Введите название папки:\n");
    GetStr(S,15);
    DBSize=LoadDB(S,DB,MAX);
    printf("OK\n");
    fclose(f);
    break;
default:
printf("Данное действие невозможно\n");
break;
}
}
}