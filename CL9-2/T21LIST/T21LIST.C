#include "fanc.h"

void main(void)
{
int flag=1, a, b;
LIST *List=NULL;
 while(flag!=0)
 {
  Display(List);
  printf(" 0-��室 \n 1-�������� � ��砫� \n 2-�������� � ����� \n 3-������� �� ��砫� \n 4-������� � ���� \n 5-�������� �� ������ \n 6-������� �� ������ \n 7-������� ���� ᯨ᮪\n");
  switch(getch())
  {
   case '0':
    flag=0;
   break;
   case '1':
    printf("������:\n");
    scanf("%i", &a);
    if(AddToBegin(&List, a))
      printf("OK!\n");
    else
      printf("Error\n");
   break;
   case '2':
    printf("������:\n");
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
    printf("������ �᫮ � ���� �१ �஡��:\n");
    scanf("%i %i", &a, &b);
    if(AddToN(&List, a, b))
      printf("OK!\n");
    else
      printf("Error\n");
   break;
   case '6':
    printf("������ ����:\n");
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
    printf("He ��୮ ������ �������.");
   break;
  }
 }
}