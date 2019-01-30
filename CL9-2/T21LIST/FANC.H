#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

typedef struct tagList LIST;
struct tagList
{int Data;
 LIST *Next;
};

void Display(LIST *);
int AddToBegin(LIST **, int);
int AddToEnd(LIST **, int);
int DelFromBegin(LIST **,int *);
int DelFromEnd(LIST **,int *);
int AddToN(LIST **, int, int);
int DelFromN(LIST **,int *,int);