#include "fanc.h"

void Display(LIST *L)
{
if(L==NULL)
 printf("‘―¨α®ª ―γαβ!\n");
else
 while(L!=NULL)
 {
  printf("%4i ", L->Data);
  L=L->Next;
  printf(L==NULL?"\n":", ");
 }
}

int AddToBegin(LIST **L, int NewData)
{
LIST *NewEl;

 if((NewEl=malloc(sizeof(LIST)))==NULL)
  return 0;
 NewEl->Data=NewData;
 NewEl->Next=*L;
 *L=NewEl;
return 1;
 }

int AddToEnd(LIST **L, int NewData)
{
LIST *NewEl;

 if((NewEl=malloc(sizeof(LIST)))==NULL)
  return 0;
 NewEl->Data=NewData;
 NewEl->Next=NULL;
 while(*L!=NULL)
  L=&(*L)->Next;
 *L=NewEl;
return 1;
}

int DelFromBegin(LIST **L,int *El)
{
LIST *OldEl=*L;

 if(*L==NULL)
  return 0;
 *L=(*L)->Next;
 *El=OldEl->Data;
 free(OldEl);
return 1;
}

int DelFromEnd(LIST **L,int *El)
{
LIST *OldEl;

 if(*L==NULL)
  return 0;
 if((OldEl=malloc(sizeof(LIST)))==NULL)
  return 0;
 while((*L)->Next!=NULL)
  L=&(*L)->Next;
 OldEl=*L;
 *L=NULL;
 *El=OldEl->Data;
 free(OldEl);
return 1;
}

int AddToN(LIST **L, int NewData, int n)
{
 int i=1;
 LIST *NewEl;

 if((NewEl=malloc(sizeof(LIST)))==NULL)
  return 0;
 while(i<n && *L!=NULL)
 {
  i++;
  L=&(*L)->Next;
 }
 NewEl->Next=*L;
 NewEl->Data=NewData;
 *L=NewEl;
return 1;
}

int DelFromN(LIST **L,int *El,int n)
{
 int i=1;
 LIST *OldEl;

if(*L==NULL)
 return 0;
if((OldEl=malloc(sizeof(LIST)))==NULL)
 return 0;
while(i<n && (*L)->Next!=NULL)
  {
   i++;
   L=&(*L)->Next;
  }
 OldEl=*L;
 *L=(*L)->Next;
 *El=OldEl->Data;
 free(OldEl);
return 1;
}