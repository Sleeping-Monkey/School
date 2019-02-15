/*Romanova Polina 10-2 24/12/2013*/


#include "ugl.h" 

void Scanner(char *S)
{
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
     CurTok.Op = *S++;
     CurTok.Id = TOK_OPER;
   }
   else if(IsDigit(*S))
   {
     CurTok.Id = TOK_NUM;
     CurTok.x = 0;
     while(IsDigit(*S))
       CurTok.x = CurTok.x * 10 + (*S++ - '0');
     if(*S == '.')
       S++;
     while(IsDigit(*S))
       denum *= 10, CurTok.x += (*S++ - '0')/denum;
     denum = 1;
   }
   else if(IsAlpha(*S))
   {
     CurTok.Id = TOK_NAME;
     CurTok.Name[i++] = *S++;
     while(IsAlpha(*S) || IsDigit(*S))
       CurTok.Name[i++] = *S++;
     CurTok.Name[i] = 0;
     i = 0;
   }
   else
   {
     Error("Unrecognized charter: %c\n", *S);
   }
   if(!Put(&TokList, CurTok))
   {
     Error("No memory...\n");
   }
  }
}