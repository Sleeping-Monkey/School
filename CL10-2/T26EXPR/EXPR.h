/*Romanova Polina 10-2 24/12/2013*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <setjmp.h>
#include <stdarg.h>
#define MAX_NAME 100

typedef enum
{
  TOK_NUM, TOK_OPER, TOK_NAME
}TOKID;

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

extern STACK S1, S2;
jmp_buf ExprJumpBuf;

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
void Scanner(QUEUE *Q, char *S);
double Eval(QUEUE *Q);
int GetPrior(char Oper);
void DropOpers(STACK *S1, STACK *S2, char Oper);
void Parser(QUEUE *ResultQ, QUEUE *Q);
void Error(char *Str, ...);
void SetErrorHandle(void);
void SetValue(char *Name, double Value);
double GetValue(char *Name);
void DisplayVarTab(void);
