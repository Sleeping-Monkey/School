#include "comp.h"
void main(void)
{int H=480, W=640,n, x, y;
double y1=1, y0=-2, x1=1, x0=-2, b, a;
Comp z0, Z;
TGR_InitLibStatic();
TGR_InitMode(W,H,32);

 for(y=0;y<H;y++)
 {
  b=y1-y*(y1-y0)/H;
  for(x=0;x<W;x++)
  {
  a=x*(x1-x0)/W +x0;
  z0=ComSet(a,b);
  Z=z0;
  n=0;
  while(n<255 && (Z.Re*Z.Re+Z.Im*Z.Im)<4)
   {
    Z=ComAdd(ComMult(Z,Z),z0);
    n++;
   }
   TGR_PutPixel(x,y,TGR_RGB(n+10,n-5,n-5));
  }
 }
 getch();
 TGR_CloseLib();
}