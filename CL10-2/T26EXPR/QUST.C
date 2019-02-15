/*Romanova Polina 10-2 24/12/2013*/

#include "expr.h"

int Push(STACK *S, TOK NewTok)
{
  LIST *NewEl;
  if((NewEl = malloc(sizeof(LIST))) == NULL)
   Error("No Memory");
  NewEl->T = NewTok;
  NewEl->Next = S->Top;
  S->Top = NewEl;
  return 1;
}


int Put(QUEUE *Q, TOK NewTok)
{
 LIST *NewEl;
 if((NewEl = malloc(sizeof(LIST))) == NULL)
  Error("No Memory");
 NewEl->T = NewTok;
    NewEl->Next = NULL;
  if(Q->Head == NULL)
    Q->Head = Q->Tail = NewEl;
  else
  {
    Q->Tail->Next = NewEl;
    Q->Tail = Q->Tail->Next;
  }
  return 1;
}

int Pop(STACK *S, TOK *OldTok)
{
 LIST *OldEl;
 if(S->Top == NULL)
   return 0;
 OldEl = S->Top;
 S->Top = S->Top->Next;
 *OldTok = OldEl->T;
  free(OldEl);
  return 1;
}

int Get(QUEUE *Q, TOK *OldTok)
{
 LIST *OldEl;
 if(Q->Head == NULL)
  return 0;
 OldEl = Q->Head;
 Q->Head = Q->Head->Next;
 *OldTok = OldEl->T;
 free(OldEl);
 return 1;
}


void DisplayL(LIST *L)
{
 while(L != NULL)
 {
   TokPrint(L->T);
   L = L->Next;
 }
}

void DisplayS(STACK *S)
{
 DisplayL(S->Top);
}

void DisplayQ(QUEUE *Q)
{
 DisplayL(Q->Head);
}

void DelL(LIST **L)
{
 LIST *Tmp;
 while(*L != NULL)
 {
  Tmp = *L;
  *L = (*L)->Next;
  free(Tmp);
 }
}

void DelS(STACK *S)
{
 DelL(&S->Top);
}

void DelQ(QUEUE *Q)
{
 DelL(&Q->Tail);
 Q->Head = NULL;
}