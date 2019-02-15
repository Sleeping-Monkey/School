#include "expr.h"

typedef struct tagVARLIST VARLIST;
static struct tagVARLIST
{
  char Name[MAX_NAME];
  double Value;
  VARLIST *Next;
} *VarTable = NULL;

void SetValue(char *Name, double Value)
{
  VARLIST **ptr = & VarTable;
  while(*ptr != NULL)
    if(strcmp((*ptr)->Name, Name) == 0)
    {
      (*ptr)->Value = Value;
      return;
    }
    else
      ptr = &(*ptr)->Next;
  if((*ptr = malloc(sizeof(VARLIST))) == NULL)
    return;
  strncpy((*ptr)->Name, Name, MAX_NAME - 1);
  (*ptr)->Value = Value;
  (*ptr)->Next = NULL;
}

double GetValue(char *Name)
{
  VARLIST **ptr = & VarTable;
  while(*ptr != NULL)
    if(strcmp((*ptr)->Name, Name) == 0)
      return (*ptr)->Value;
    else
      ptr = &(*ptr)->Next;
    return 0;
}

void DisplayVarTab(void)
{
  VARLIST **ptr = & VarTable;
  while(*ptr != NULL)
  {
    printf("%s = %g\n", (*ptr)->Name, (*ptr)->Value);
    ptr = &(*ptr)->Next;
  }
}