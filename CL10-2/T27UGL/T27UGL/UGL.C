/*Romanova Polina 10-2 25.02.2014*/
#include "ugl.h"

void DoCmd(CMD *C)
{
  while(C != NULL)
  {
    if(C->Id == CMD_EXPR)
    Eval(C->Expr);
    else if(C->Id == CMD_IF)
    if(Eval(C->Expr))
        DoCmd(C->Cmd1);
      else
        DoCmd(C->Cmd2);
    else if(C->Id == CMD_WHILE)
      while(Eval(C->Expr))
        DoCmd(C->Cmd1);
    C = C->Next;
  }
}

CMD * CmdInit(void)
{
  CMD *C = malloc(sizeof(CMD));
  memset(C, 0, sizeof(CMD));
    return C;
}

void ParseProgram(CMD **Prg)
{
  Next();
  while(!IsEOTL)
  {
    *Prg = CmdInit();
    ParseCmd(*Prg);
    Prg = &(*Prg) ->Next;
  }
}

void ParseCmd(CMD *C)
{
  if(IsTokName("If"))
  {
    C->Id = CMD_IF;
    ParseName("If");
    ParseOp('(');
    ParseExpr(&C->Expr);
    ParseOp(')');
    ParseCmd(C->Cmd1=CmdInit());
    if(IsTokName("Else"))
    {
      ParseName("Else");
      ParseCmd(C->Cmd2 = CmdInit());
    }
  }
  else if(IsTokName("While"))
  {
   ParseName("While");
   ParseOp('(');
   ParseExpr(&C->Expr);
   ParseOp(')');
   ParseCmd(C->Cmd1 = CmdInit());
   while(C->Expr)
   {
   }
  }
  else if(IsTokOp('{'))
  {
    ParseOp('{');
    while(!IsTokOp('}'))
    {
      ParseCmd(C);
      if(!IsTokOp('}'))
        C->Next = CmdInit(), C = C->Next;
    }
    ParseOp('}');
  }
  else
  {
    C->Id = CMD_EXPR;
    ParseExpr(&C->Expr);
    ParseOp(';');
  }
} 
