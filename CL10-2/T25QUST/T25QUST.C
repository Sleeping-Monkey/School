#include "qust.h"

void main()
{
 STACK St={NULL};
 QUEUE Qu={NULL};
 int flag=1, f;
 char s[100];
 while(flag)
 {
          printf("STACK: ");
          DisplayS(&St);
          printf("\nQUEUE: ");
          DisplayQ(&Qu);
          printf("\n");
          printf("\n0 - Exit\n"
          "1 - Push\n"
          "2 - Pop\n"
          "3 - Put\n"
          "4 - Get\n"
          "5 - random Push\n"
          "6 - random Put\n"
          "7 - Delet\n");
   switch(getch())
   {
     case '1':
     {
       printf("Введите строку:\n");
       scanf("%s", s);
       Push(&St, s);
       break;
     }
     case '0':
     {
      flag=0;
      break;
     }
     case '3':
     {
       printf("Введите строку:\n");
       scanf("%s", s);
       Put(&Qu, s);
      break;
     }
     case '2':
     {
      Pop(&St, s);
      break;
     }
     case '4':
     {
      Get(&Qu, s);
      break;
     }
     case '5':
     {
      printf("Введите кол-во элементов:\n");
      scanf("%d", &f);
      while(f-->0)
      {
        sprintf(s, "%i", rand());
        Push(&St, s);
      }
      break;
     }
     case '6':
     {
      printf("Введите кол-во элементов:\n");
      scanf("%d", &f);
      while(f-->0)
      {
        sprintf(s, "%i", rand());
        Put(&Qu, s);
      }
      break;
     }
     case '7':
     {
       DelS(&St);
       DelQ(&Qu);
      break;
     }
   }
 }
}