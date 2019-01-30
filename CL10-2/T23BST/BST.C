#include "bst.h"

int AccessTree(TREE **T, int key)
{
 if(*T==NULL)
 {
   *T=malloc(sizeof(TREE));
   if(*T==NULL)
   {
     printf("Error\n");
     return 0;
   }
   (*T)->Key=key;
   (*T)->Less=(*T)->More=NULL;
   return 2;
 }

 if((*T)->Key==key)
 {
    printf("%i already exists...\n", key);
    return 1;
 }

 if((*T)->Key>key)
   return AccessTree(&(*T)->Less, key);
 return AccessTree(&(*T)->More, key);
}

int AccessTree2(TREE **T, int key)
{
 while(*T!=NULL)
 {
  if((*T)->Key==key)
  {
    printf("%i already exists...\n", key);
    return 1;
  }

  if((*T)->Key>key)
    T=&(*T)->Less;
  else
    T=&(*T)->More;
 }
 (*T)=malloc(sizeof(TREE));
 if((*T)==NULL)
 {
   printf("Error\n");
   return 0;
 }

 (*T)->Key=key;
 (*T)->Less=(*T)->More=NULL;
 return 2;
}

void DrawTree(TREE *T, int level)
{
 if(T!=NULL)
 {
   DrawTree(T->More, level+1);
   printf("%*c%d\n", level*3, ' ', T->Key);
   DrawTree(T->Less, level+1);
 }
}

void PutTree(TREE *T)
{
 if(T==NULL)
   printf("*");
 else
 {
   printf("%d(",T->Key);
   PutTree(T->Less);
   printf(",");
   PutTree(T->More);
   printf(")");
 }
}

void ClearTree(TREE **T)
{
 if(*T!=NULL)
 {
   ClearTree(&(*T)->Less);
   ClearTree(&(*T)->More);
   free(*T);
   *T=NULL;
 }
}

void AddToTree(TREE **T, int n)
{
 int k;
 while(n>0)
 {
  k=AccessTree2(&T, rand()%100);
  if(k==2)
    n--;
 }
}

void PT(TREE *T, FILE *F)
{
 if(T==NULL)
   return;
 else
 {
   fprintf(F, "%d ",T->Key);
   PT(T->Less, F);
   PT(T->More, F);
 }
}

void SaveTree(TREE *T, char *fname)
{
 FILE *fout;
 fout=fopen(fname, "w");
   if(T!=NULL)
   {
     PT(T, fout);
     fprintf(fout, "\n");
   }
fclose(fout);
}

void RTree(TREE **T, char *fname)
{
 int x;
 FILE *fin;
 if((fin=fopen(fname,"r"))==NULL)
   printf("Error\n");
 else
 {
   fscanf(fin, "%d", &x);
   if(x!=-10)
   {
     (*T)->Key=x;
     RTree(&(*T)->Less, fname);
     RTree(&(*T)->More, fname);
   }
   else
    (*T)=NULL;
}
fclose(fin);
}

int Linearize(TREE **T)
{
 TREE **P;
 int n=0;
 while((*T)!=NULL)
 {
  while((*T)->Less!=NULL)
  {
   P=&(*T)->Less;
   while(*P!=NULL)
     P=&(*P)->More;
   *P=*T;
   *T=(*T)->Less;
   (*P)->Less=NULL;
  }
  T=&(*T)->More;
  n++;
 }
return n;
}

void BalanceTree(TREE **T, int n)
{
int i;
TREE **P;
if(n<=1)
return;
P=T;
for(i=0;i< n/2;i++)
 P=&(*P)->More;
(*P)->Less=*T;
*T=*P;
*P=NULL;
 BalanceTree(&(*T)->Less, n/2);
 BalanceTree(&(*T)->More, n-n/2-1);
}

void Del(TREE **T, int key)
{
 TREE **P, *prev;
 while(*T!=NULL && (*T)->Key!=key)
 {
  if(key<((*T)->Key))
    T=&(*T)->Less;
  else
    T=&(*T)->More;
 }
 if(*T== NULL)
   return 1;
 P=&(*T)->Less;
 while(*P!=NULL)
   P=&(*P)->More;
 *P=(*T)->More;
 prev=*T;
 *T=(*T)->Less;
 free(prev);
 return 0;
}

