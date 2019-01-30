#include "a.h"
void main(void)
{int i;
 char s[N];
 printf("Введите строку, длинна которой не привышает 100\n");
 GetStr(s,N);
 printf("\nКоличесво знаков: %i\n",LenStr(s));
 printf("\nКоличесво букв: %i\n",Colvb(s));
 printf("\nКоличесво цифр: %i\n",Colvch(s));
 if(Sim(s,LenStr(s)))
   printf("\nСтрока симметрична\n");
 else
   printf("\nСтрока не симметрична\n");
   printf("\nКоличесво слов: %i\n",Colvc(s));
   printf("\nКоличество паллиндромов: %i\n", Pal(s));
   printf("\nСумма чисел: %i\n", Sum(s));
   Bez(s);
   printf("\nmass:\n");
  /* for(i=0;i<LenStr(s);i++)   */
   printf("%s", s);
   printf("\n");
}
