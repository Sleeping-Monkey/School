#include <string.h>
#include <tgrp.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef unsigned char byte;
typedef byte RGB[3];

typedef struct
{
 int W,H;
 RGB**Rows;
}PIC;

typedef struct
{char *Name;
int A[3][3], Frac,Bias;
}FILTER;

void GetStr(char *, int);
int PicCreate(PIC *, int, int);
int PicLoad(char *, PIC *);
void PicDraw(PIC *, int, int);
void PicFree(PIC *);
void LUTSetNegative(byte *LUT);
void LUTApply(PIC *, PIC *, byte *LUT);
void LUTSetBrightness(byte *LUT, float);
void LUTSetContrast(byte *LUT, int, int);
void LUTSetGamma(byte *LUT, float);
/*int PicGet(PIC *,int,int);
void LinFilterApply(PIC *, PIC *, FILTER *); */