#include "dpic.h"

void GetStr(char *Str, int n)
{
int i=0;
char ch;
while((ch=getchar())!='\n')
if(Str!=NULL && i<n-1)
Str[i++]=ch;
if(Str!=NULL && i<n)
Str[i]=0;}



int PicCreate(PIC *P, int w, int h)
{
 int i;

 P->W=P->H=0;
 P->Rows=NULL;
 P->Rows=malloc(sizeof(RGB*)*h);
 if(P->Rows==NULL)
  return 0;
 for(i=0;i<h;i++)
  if((P->Rows[i]=malloc(w*sizeof(RGB)))==NULL)
  {
   while(i-->0)
    free(P->Rows[i]);
   free(P->Rows);
   P->Rows=NULL;
   return 0;
  }
  else
   memset(P->Rows[i],0,w*3);
   P->W=w;
   P->H=h;
   return 1;
}

int PicLoad(char *fname, PIC *P)
{
 FILE *f;
 int w, h, i;

 if((f=fopen(fname,"rb"))==NULL)
  return 0;
 fread(&w,2,1,f);
 fread(&h,2,1,f);
 if(!PicCreate(P,w,h))
 {
  fclose(f);
  return 0;
 }
 for(i=0;i<h;i++)
  fread(P->Rows[i], 3, w,f);
 fclose(f);
 return 1;
}

void PicDraw(PIC *P, int x0, int y0)
{
 int x,y;

 for(y=0;y<P->H;y++)
  for(x=0;x<P->W;x++)
   TGR_PutPixel(x+x0,y+y0,TGR_RGB(P->Rows[y][x][2],
                                  P->Rows[y][x][1],
                                  P->Rows[y][x][0]));
}

void PicFree(PIC *P)
{
 int i;

 if(P->Rows!=NULL)
 {
  for(i=0;i<P->H;i++)
   free(P->Rows[i]);
  free(P->Rows);
  P->Rows = NULL;
 }
 P->W = P->H = 0;
}