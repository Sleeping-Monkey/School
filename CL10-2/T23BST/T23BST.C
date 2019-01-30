/*Romanova Polina 10-2 08.10.13*/
#include "bst.h"

void main(void)
{
 int key, flag=1, s;
 char fname;
 TREE *Root=NULL;
 while(flag)
 {
  PutTree(Root);
   printf("\n0 - Exit\n"
          "1 - Access\n"
          "2 - Access 2\n"
          "3 - Draw\n"
          "4 - Delet\n"
          "5 - Add\n"
          "6 - Save\n"
          "7 - Load\n"
          "8 - Delete Element\n"
          "9 - Balance\n");
   switch(getch())
   {
     case '1':
     {
       printf("Введите key\n");
       scanf("%d", &key);
       s=AccessTree(&Root, key);
       break;
     }
     case '0':
     {
      flag=0;
      break;
     }
     case '2':
     {
      printf("Введите key\n");
       scanf("%d", &key);
       s=AccessTree2(&Root, key);
       break;
     }
     case '3':
     {
      DrawTree(Root,1);
      break;
     }
     case '4':
     {
      ClearTree(&Root);
      break;
     }
     case '5':
     {
      printf("Введите количество величин:\n");
      scanf("%d", &s);
      AddToTree(&Root,s);
      break;
     }
     case '6':
     {
      printf("Введите название файла\n");
      scanf("%s", &fname);
      SaveTree(Root, &fname);
      break;
     }
     case '7':
     {
      printf("Введите название файла\n");
      scanf("%s", &fname);
      RTree(&Root, &fname);
      break;
     }
     case '8':
     {
      printf("Введите key\n");
      scanf("%d", &s);
      Del(&Root, s);
      break;
     }
     case '9':
     {
      s=Linearize(&Root);
      printf("%d\n", s);
      BalanceTree(&Root, s);
      break;
     }
   }
 }

}
