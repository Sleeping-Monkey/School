#include "dpic.h"
/*
int PicGet(PIC *P,int x,int y)
{
x=(x+P->W)%P->W;
y=(y+P->H)%P->H;
return
}

void LinFilterApply(PIC *Dest, PIC *Src, FILTER *f)
{int x, y, c, i, j, rez;
for(y=0;y<Dest->H;y++)
   for(x=0;x<Dest->W;x++)
      for(c=0;c<3;c++)
      {
      rez=0;
      for(i=0;i<3;i++)
         for(j=0;j<3;j++)
         rez+=PicGet(Src,x-1+j,y-1+i)*f->A[i][j];
         rez/=f->Frac;
         rez+=f->Bias;
      }
} */