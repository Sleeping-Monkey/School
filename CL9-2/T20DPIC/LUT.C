#include "dpic.h"

void LUTSetNegative(byte *LUT)
{int i;
for(i=0;i<256;i++)
LUT[i]=255-i;
}

void LUTSetBrightness(byte *LUT, float dI)
{
int i, x;
for(i=0;i<256;i++)
{
x=i+dI;
if(x<0)
x=0;
else if(x>255)
x=255;
LUT[i]=x;
}
}

void LUTSetContrast(byte *LUT, int A, int B)
{
int i, x;
for(i=0;i<256;i++)
{if(i<A)
x=0;
else if(i>B)
x=255;
else
x=255*(i-A)/(B-A);
LUT[i]=x;
}
}

void LUTSetGamma(byte *LUT, float g)
{
int i;
for(i=0;i<256;i++)
LUT[i]=255*pow(((float)i/255),1/g);
}

void LUTApply(PIC *Dest, PIC *Src, byte *LUT)
{
int x, y, c;
for(y=0;y<Src->H;y++)
   for(x=0;x<Src->W;x++)
   for(c=0;c<3;c++)
   Dest->Rows[y][x][c]=LUT[Src->Rows[y][x][c]];
   }