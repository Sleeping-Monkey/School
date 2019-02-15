/*Romanova Polina 10-2 25.02.2014*/
#include "ugl.h"


void Error(char *Str, ...)
{
  va_list ap;
  va_start(ap, Str);
  vprintf(Str, ap);
 longjmp(ExprJumpBuf, 1);
}


void main (void)
{
  char s[1000];
  CMD *Prg;
  //double res;
  FILE *F;
  if(setjmp(ExprJumpBuf))
  {
    DisplayL(&S1.Top);
    printf("\n");
    DisplayL(&S2.Top);
    printf("\n %s\n", s);
    DisplayVarTab();
    printf("\n");
    DisplayQ(TokList);
    DelL(&S1.Top);
    DelL(&S2.Top);
    getch();
    return;
  }
 // if((F=fopen("a.txt", "r"))!=NULL)
 {
  while(fgets(s, sizeof(s) -1, F)!=NULL)
    Scanner(s);
  fclose(F);  
  }

  ParseProgram(&Prg);
  
  DoCmd(Prg);

  getch();
}