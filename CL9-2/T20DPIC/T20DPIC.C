#include "dpic.h"

void main(void)
{
char begf[50]="x:\\PICS\\";
char name[20], endf[10]=".g24";
byte LUT[256];
PIC P={0}, P1={0};
int flag=1;
/*static FILTER Filters[]={{"Blur",{1,1,1},{1,1,1},{1,1,1},9,0},
                         {"Gaus",{1,2,1},{2,4,2},{1,2,1},16,0},
                         {"HipassBig",{-1,-1,-1},{-1,9,-1},{-1,-1,-1},1,0},
                         {"HipassSmall",{0,-1,0},{-1,5,-1},{0,-1,0},1,0},
                         {"GradBig",{-1,-1,-1},{-1,8,-1},{-1,-1,-1},1,128},
                         {"EmbossSmallNW",{-1,0,0},{0,1,0},{0,0,0},1,128},
                         {"EmbossBig",{-1,-1,-1},{-1,2,-1},{-1,-1,-1},1,128}}
                               */
while(flag)
{
printf(" 0 - Выход\n 1 - Загрузка\n 2 - Отображение\n 3 - Луты\n 4 - Фильтры\n");
switch(getch())
{
case '0':
PicFree(&P);
PicFree(&P1);
flag=0;
break;
case '1':
printf("Name?: ");
GetStr(name,20);
strcat(begf, name);
strcat(begf, endf);
puts(begf);
if(PicLoad(begf,&P))
  if(PicCreate(&P1,P.W,P.H))
  printf("OK!\n");
  else
   printf("No P1\n");
  else
  printf("No P\n");
  break;
  case '2':
  TGR_InitLibStatic();
  TGR_InitMode(800,600, 32);
  PicDraw(&P, 0, 0);
  PicDraw(&P1, P.W+15, 0);
  getch();
  TGR_CloseLib();
  break;
  case '3':
  printf("\n    0 - Negative\n     1 - Brightness\n     2 - Contrast\n     3 - Gamma\n");
  switch(getch())
  {
  case '0':
  LUTSetNegative(LUT);
  break;
  case '1':
  LUTSetBrightness(LUT, 100);
  break;
  case '2':
  LUTSetContrast(LUT,10,50);
  break;
  case '3':
  LUTSetGamma(LUT, 0.64);
  break;
  }
  LUTApply(&P1,&P,LUT);
  printf("OK!\n");
  break;
  case '4':
  break;
  default:
  printf("Error!");
  break;
  }
}
}