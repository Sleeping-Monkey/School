#include "fanc.h"

void main(void)
{
int flag=1, a, b;
LIST *List=NULL;
 while(flag!=0)
 {
  Display(List);
  printf(" 0-Выход \n 1-Добавить в начало \n 2-Добавить в конец \n 3-Удалить из начала \n 4-Удалить с конца \n 5-Добавить по номеру \n 6-Удалить по номеру \n 7-Почистить весь список\n");
  switch(getch())
  {
   case '0':
    flag=0;
   break;
   case '1':
    printf("Введите:\n");
    scanf("%i", &a);
    if(AddToBegin(&List, a))
      printf("OK!\n");
    else
      printf("Error\n");
   break;
   case '2':
    printf("Введите:\n");
    scanf("%i", &a);
    if(AddToEnd(&List, a))
      printf("OK!\n");
    else
      printf("Error\n");
   break;
   case '3':
    if(DelFromBegin(&List, &a))
      printf("OK! %i\n", a);
    else
      printf("Error\n");
   break;
   case '4':
    if(DelFromEnd(&List, &a))
      printf("OK! %i\n", a);
    else
      printf("Error");
   break;
   case '5':
    printf("Введите число и место через пробел:\n");
    scanf("%i %i", &a, &b);
    if(AddToN(&List, a, b))
      printf("OK!\n");
    else
      printf("Error\n");
   break;
   case '6':
    printf("Введите место:\n");
    scanf("%i", &b);
    if(DelFromN(&List, &a, b))
      printf("OK! %i\n", a);
    else
      printf("Error\n");
   break;
   case '7':
    while(List!=NULL)
     DelFromEnd(&List, &a);
    if(List==NULL)
      printf("OK!\n");
    else
      printf("Error\n");
   break;
   default:
    printf("He верно задана команда.");
   break;
  }
 }
}