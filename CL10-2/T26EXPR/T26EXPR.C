/*Романова Полина 10-2 24.12.2013*/

#include "expr.h"

void main(void)
{
 char S[200];
 QUEUE Q = {NULL}, NewQ = {NULL};
 double res;
 printf("Expression:\n");
 GetStr(S, sizeof(S));
 Scanner(&Q, S);
   printf("Lexer queue: ");
   DisplayQ(&Q);
 Parser(&NewQ, &Q);
   printf("New lexer queue: ");
   DisplayQ(&NewQ);
   res = Eval(&NewQ);
   printf("\nEval = %g \n", res);
   DisplayVarTab();
   if(setjmp(ExprJumpBuf))
    SetErrorHandle();
  getchar();
}