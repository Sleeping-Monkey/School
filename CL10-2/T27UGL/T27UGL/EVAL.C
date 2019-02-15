/*Romanova Polina 10-2 24/12/2013*/

#include "ugl.h"

void GetStr(char *S, int n)
{
  int i=0;
  char c;
 while((c=getchar())!='\n' && i < n-1)
   S[i++]=c;
 S[i]='\0';
}

void TokPrint(TOK T)
{
  switch(T.Id)
  {
    case TOK_NUM:
      {
        printf("%g, ", T.x);
        break;
      }
    case TOK_OPER:
      {
        printf("%c, ", T.Op);
        break;
      }
    case TOK_NAME:
      {
        printf("%s, ", T.Name);
        break;
      }
  }
}

int IsSpace(char c)
{
 if(c == ' ' || c == '\n' || c == '\t' || c == '\r')
   return 1;
 return 0;
}

int IsAlpha(char c)
{                                         
 if(('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z') || c == '_')
   return 1;
 return 0;
}

int IsDigit(char c)
{
 if(c >= '0' && c <= '9')
   return 1;
 return 0;
}

double Eval(LIST *L)
{
  STACK S = {NULL};
  TOK A, B;

  while(L->Next != NULL)
  {
    if(IsTokAnyNum() || IsTokAnyName())
      Push(&S, CurTok);
    else if(IsTokAnyOp())
    {

      Pop(&S, &A);
      if(A.Id == TOK_NAME)
        A.x = GetValue(A.Name);
      Pop(&S, &B);
      if(!IsTokOp('=') && B.Id == TOK_NAME)
      {
        B.x = GetValue(B.Name);
        B.Id = TOK_NUM;
      }
      switch(CurTok.Op)
      {
      case '+':
        {
         B.x += A.x;
         break;
        }
      case '-':
        {
          B.x -= A.x;
         break;
        }
      case '*':
        {
         B.x *= A.x;
         break;
        }
      case '/':
        {
          B.x /= A.x;
         break;
        }
      case '%':
        {
          B.x = (int)B.x % (int)A.x;
          break;
        }
      case '=':
        {
          if(B.Id == TOK_NAME)
            SetValue(B.Name, A.x);
          B.x = A.x;
          B.Id = TOK_NUM;
          break;
        }
      case ',':
        {
          B.x = A.x;
          break;
        }
      }
      Push(&S, B);
    }
    L = L->Next;
  }
  return S.Top->T.x;
}