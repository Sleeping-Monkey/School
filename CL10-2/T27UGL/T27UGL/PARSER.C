/*Romanova Polina 10-2 24/12/2013*/
#include "ugl.h"

int GetPrior(char Oper)
{
  switch(Oper)
  {
  case '(':
    return 0;
  case ')':
    return 1;
  case ',':
    return 2;
  case '=':
    return 3;
  case '+':
  case '-':
  case '@':
    return 4;
  case '*':
  case '/':
  case '%':
    return 5;
  default:
    return -1;
  }
}

void DropOpers(STACK *S1, STACK *S2, char Oper)
{
  TOK T;
  while(S2->Top != NULL && GetPrior(S2->Top->T.Op) >= GetPrior(Oper))
  {
    Pop(S2, &T);
    Push(S1, T);
  }
}

void ParseExpr(LIST **L)
{
  TOK T;
  int IsOkey = 1;
  enum
  {
    ST_PREFIX, ST_SUFFIX, ST_DONE, ST_END
  }state = ST_PREFIX;
  while(state != ST_END)
  {

    switch(state)
    {
    case ST_PREFIX:
     {
       if(IsTokAnyNum() || IsTokAnyName())
      {
         Push(&S1,CurTok);
         state = ST_SUFFIX;
      }
      else if(IsTokOp('('))
        Push(&S2,CurTok);
      else if(IsTokOp('@'))
      {
        DropOpers(&S1, &S2, CurTok.Op);
        Push(&S2, CurTok);
      }
      else
          Error("Expected number or '(' \n");
      break;
     }
    case ST_SUFFIX:
      {
        if(!IsTokAnyOp())
          Error("Expected Oper %g %c\n", CurTok.x, CurTok.Op);
        else if(IsTokOp(')'))
        {
         DropOpers(&S1, &S2, CurTok.Op);
          Pop(&S2, &CurTok);
        }
        else if(IsTokOp(';'))
        {
          DropOpers(&S1, &S2, '(');
          state = ST_DONE;
        }
        else
        {
          DropOpers(&S1, &S2, CurTok.Op);
          Push(&S2, CurTok);
          state = ST_PREFIX;
        }
        break;
       }
    case ST_DONE:
      {
        while(Pop(&S1, &T))
              Push(&S2, T);
        while(Pop(&S2, &T))
   //           Put(ResultQ, T);
        state = ST_END;
        break;
      }
    }
  }
  }