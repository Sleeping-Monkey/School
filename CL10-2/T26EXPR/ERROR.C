#include "expr.h"


void Error(char *Str, ...)
{
  va_list ap;
  va_start(ap, Str);
  vprintf(Str, ap);
 longjmp(ExprJumpBuf, 1);
}

void SetErrorHandle(void)
{
    DisplayL(&S1.Top);
    printf("\n");
    DisplayL(&S2.Top);
    
    DelL(&S1.Top);
    DelL(&S2.Top);
}