/*Romanova Polina 10-2 24/12/2013*/

#include "expr.h"

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

double Eval(QUEUE *Q)
{
  STACK S = {NULL};
  TOK W, A, B;

  while(Get(Q, &W))
  {
    if(W.Id == TOK_NUM || W.Id == TOK_NAME)
      Push(&S, W);
    else if(W.Id == TOK_OPER)
    {

      Pop(&S, &A);
      if(A.Id == TOK_NAME)
        A.x = GetValue(A.Name);
      Pop(&S, &B);
      if(W.Op != '=' && B.Id == TOK_NAME)
      {
        B.x = GetValue(B.Name);
        B.Id = TOK_NUM;
      }
      switch(W.Op)
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

  }
  return S.Top->T.x;
}