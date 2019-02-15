/*Romanova Polina 10-2 25.02.2014*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <setjmp.h>
#include <stdarg.h>
#include <string.h>
#define MAX_NAME 100

typedef enum
{
  TOK_NUM, TOK_OPER, TOK_NAME
}TOKID;

typedef enum
{
  CMD_EXPR, CMD_IF, CMD_WHILE
}CMDID;
   
typedef struct
{
 TOKID Id;
 double x;
 char Op;
 char Name[200];
}TOK;

typedef struct tagLIST LIST;
struct tagLIST
{
 TOK T;
 LIST *Next;
};

typedef struct
{
 LIST *Top;
}STACK;

typedef struct
{
 LIST *Head, *Tail;
}QUEUE;

typedef struct tagCMD CMD;
struct tagCMD
{
  LIST *Expr;
  CMDID Id;
  CMD *Cmd1, *Cmd2, *Next;
};

STACK S1, S2;
jmp_buf ExprJumpBuf;

QUEUE *TokList;
TOK CurTok;
#define FALSE 0
#define TRUE 1
static int IsEOTL = FALSE;

#define Next() \
  (IsEOTL ? Error("Unexpected end-of-data"):\
  Get(&TokList, &CurTok)? (void)0 : \
  (void)(IsEOTL = TRUE))  

#define IsTokAnyOp() \
  (!IsEOTL && CurTok.Id == TOK_OPER)
#define IsTokOp(C) \
  (!IsEOTL && CurTok.Id == TOK_OPER && CurTok.Op == (C))
#define ParseAnyOp()\
  (IsTokAnyOp() ? Next() : Error("Expected any operation"))
#define ParseOp(C)\
  (IsTokOp(C) ? Next() : Error("Expected '%c'", (C)))
#define IsTokAnyName()\
  (!IsEOTL && CurTok.Id == TOK_NAME)
#define IsTokName(S)\
  (IsTokAnyName() && strcmp(CurTok.Name, (S)) == 0)
#define ParseName(S)\
  (IsTokName(S) ? Next() : Error("Expected '%s'", (S)))
#define IsTokAnyNum() \
  (!IsEOTL && CurTok.Id == TOK_NUM)
#define ParseNum(X)\
  (IsTokAnyNum() ? (void)(*X = CurTok.Num), Next() : \
  Error("Expected number"))

int Push(STACK *S, TOK NewTok);
int Put(QUEUE *Q, TOK NewTok);
int Pop(STACK *S, TOK *OldTok);
int Get(QUEUE *Q, TOK *OldTok);
void DisplayL(LIST *L);
void DisplayS(STACK *S);
void DisplayQ(QUEUE *Q);
void DelL(LIST **L);
void DelS(STACK *S);
void DelQ(QUEUE *Q);
void TokPrint(TOK T);
int IsSpace(char c);
int IsAlpha(char c);
int IsDigit(char c);
void Scanner(char *S);
double Eval(LIST *L);
int GetPrior(char Oper);
void DropOpers(STACK *S1, STACK *S2, char Oper);
void ParseExpr(LIST **L);
void Error(char *Str, ...);
void SetValue(char *Name, double Value);
double GetValue(char *Name);
void DisplayVarTab(void);
void DoCmd(CMD *C);
CMD * CmdInit(void);
void ParseProgram(CMD **Prg);
void ParseCmd(CMD *C);
  