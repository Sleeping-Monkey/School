#include "a.h"
void main(void)
{int i;
 char s[N];
 printf("������ ��ப�, ������ ���ன �� �ਢ�蠥� 100\n");
 GetStr(s,N);
 printf("\n�����᢮ ������: %i\n",LenStr(s));
 printf("\n�����᢮ �㪢: %i\n",Colvb(s));
 printf("\n�����᢮ ���: %i\n",Colvch(s));
 if(Sim(s,LenStr(s)))
   printf("\n��ப� ᨬ����筠\n");
 else
   printf("\n��ப� �� ᨬ����筠\n");
   printf("\n�����᢮ ᫮�: %i\n",Colvc(s));
   printf("\n������⢮ �������஬��: %i\n", Pal(s));
   printf("\n�㬬� �ᥫ: %i\n", Sum(s));
   Bez(s);
   printf("\nmass:\n");
  /* for(i=0;i<LenStr(s);i++)   */
   printf("%s", s);
   printf("\n");
}
