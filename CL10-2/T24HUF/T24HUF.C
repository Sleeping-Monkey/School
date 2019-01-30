/*Romanova Polina 10-2 12.11.2013*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct tagTREE TREE;
struct tagTREE
{
 long Amount;
 char Ch;
 TREE *Left, *Right;
};

typedef struct tagCODE CODE;
struct tagCODE
{
 int Len;
 char Bits[46];
};

TREE *Nodes[256];
CODE *Codes[256];
int NodesNum;
long Freq[256];
void CountFreq(FILE *F)
{
 int i;
 for(i=0;i<256;i++)
   Freq[i]=0;
 while((i=fgetc(F)) != EOF)
     Freq[i]++;
}

void PlaceNode(char Ch, long Amount, TREE *L, TREE *R)
{
 int i=NodesNum;
 TREE *Res;
 if((Res=malloc(sizeof(TREE)))==NULL)
   return;
 Res->Ch=Ch;
 Res->Amount=Amount;
 Res->Left=L;
 Res->Right=R;
 while(i>=0 && Nodes[i]->Amount<Res->Amount)
 {
  Nodes[i+1]=Nodes[i];
  i--;
 }
 Nodes[i+1]=Res;
 NodesNum++;
}

void BuildCode(TREE *R, char *Code)
{
 int n=strlen(Code), i;
 if(R==NULL)
   return;
   Codes[R->Ch]->Len = n;
   for(i=0;i<n;i++)
     Codes[R->Ch]->Bits[i] = Code[i];
 Code[n]='0';
 Code[n+1]=0;
 BuildCode(R->Left, Code);
 Code[n]='1';
 Code[n+1]=0;
 BuildCode(R->Right, Code);
}

void main(void)
{
 TREE  *PreLast, *Last;
 int i, cod[46];
 FILE *fin;
 //fin=fopen("X:\\TXT\\CHEHOV.TXT","r");
 fin=fopen("I.TXT","r");
 CountFreq(fin);
 for(i=0;i<256;i++)
   if(Freq[i]>0)
   {
     printf("%c %d\n", i, Freq[i]);
     PlaceNode(i, Freq[i], NULL, NULL);
   }
 while(NodesNum > 1)
 {
  Last=Nodes[--NodesNum];
  PreLast=Nodes[--NodesNum];
  printf("%d %d %d\n",Last->Amount, PreLast->Amount, Last->Amount + PreLast->Amount);
  PlaceNode(-1, Last->Amount + PreLast->Amount, PreLast, Last);
 }
 //printf("%s %d", Nodes[0]->Ch, Nodes[0]->Amount);
 //BuildCode(Nodes[0], cod);
}