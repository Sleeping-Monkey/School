#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
typedef struct tagLIST LIST;
struct tagLIST
{
 char Data[100];
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

int Push(STACK *S, char *NewData);
int Put(QUEUE *Q, char *NewData);
int Pop(STACK *S, char *OldData);
int Get(QUEUE *Q, char *OldData);
void DisplayL(LIST *L);
void DisplayS(STACK *S);
void DisplayQ(QUEUE *Q);
void DelL(LIST **L);
void DelS(STACK *S);
void DelQ(QUEUE *Q);