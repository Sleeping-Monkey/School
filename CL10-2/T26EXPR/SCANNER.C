/*Romanova Polina 10-2 24/12/2013*/


#include "expr.h" 

void Scanner(QUEUE *Q, char *S)
{
 TOK T;
 double denum = 1;
 int i = 0;
 while(*S != 0)
  {
   if(IsSpace(*S))
   {
     S++;
     continue;
   }
   if(*S == '+' || *S == '-' || *S == '/' || *S == '*' || *S == '%' || *S == '^' || *S == ';' || *S == '(' || *S == ')' || *S == ',' || *S == '=' || *S == '@')
   {
     T.Op = *S++;
     T.Id = TOK_OPER;
   }
   else if(IsDigit(*S))
   {
     T.Id = TOK_NUM;
     T.x = 0;
     while(IsDigit(*S))
       T.x = T.x * 10 + (*S++ - '0');
     if(*S == '.')
       S++;
     while(IsDigit(*S))
       denum *= 10, T.x += (*S++ - '0')/denum;
     denum = 1;
   }
   else if(IsAlpha(*S))
   {
     T.Id = TOK_NAME;
     T.Name[i++] = *S++;
     while(IsAlpha(*S) || IsDigit(*S))
       T.Name[i++] = *S++;
     T.Name[i] = 0;
     i = 0;
   }
   else
   {
     Error("Unrecognized charter: %c\n", *S);
   }
   if(!Put(Q, T))
   {
     Error("No memory...\n");
   }
  }
}