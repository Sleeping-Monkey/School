#include "qust.h"


int Push(STACK *S, char *NewData)
{
  LIST *NewEl;
  if((NewEl=malloc(sizeof(LIST)))==NULL)
  return 0;
  strcpy(NewEl->Data, NewData);
  NewEl->Next=S->Top;
  S->Top=NewEl;
  return 1;
}


int Put(QUEUE *Q, char *NewData)
{
 LIST *NewEl;
 if((NewEl=malloc(sizeof(LIST)))==NULL)
  return 0;
  strcpy(NewEl->Data, NewData);
    NewEl->Next=NULL;
  if(Q->Head==NULL)
    Q->Head=Q->Tail=NewEl;
  else
  {
    Q->Tail->Next=NewEl;
    Q->Tail=Q->Tail->Next;
  }
  return 1;
}

int Pop(STACK *S, char *OldData)
{
 LIST *OldEl;
 OldEl=S->Top;
 S->Top=S->Top->Next;
 strcpy(OldData, OldEl->Data);
 free(OldEl);
  return 1;
}

int Get(QUEUE *Q, char *OldData)
{
 LIST *OldEl;
 if(Q->Head==NULL)
  return 0;
 OldEl=Q->Head;
 Q->Head=Q->Head->Next;
 strcpy(OldData, OldEl->Data);
 free(OldEl);
 return 1;
}


void DisplayL(LIST *L)
{
 while(L!=NULL)
 {
  printf("%s, ", L->Data);
  L=L->Next;
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
 while(*L!=NULL)
 {
  Tmp=*L;
  *L=(*L)->Next;
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
 Q->Head=NULL;
}