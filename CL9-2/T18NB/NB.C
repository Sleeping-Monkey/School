#include "nb.h"
void GetStr(char *Str, int n)
{
int i=0;
char ch;
while((ch=getchar())!='\n')
if(Str!=NULL && i<n-1)
Str[i++]=ch;
if(Str!=NULL && i<n)
Str[i]=0;}

void pswap(PUPIL *A, PUPIL *B)
{
PUPIL C=*A;
*A=*B;
*B=C;
}
void ReadPupil(PUPIL *P)
{
printf("�������: ");
GetStr(P->Surname,20);
printf("���: ");
GetStr(P->Name,15);
printf("��� ��������\n     ����: ");
scanf("%i",&P->Birthday.Day);
GetStr(NULL, 0);
printf("\n     �����: ");
scanf("%i",&P->Birthday.Month);
GetStr(NULL, 0);
printf("\n     ���: ");
scanf("%i",&P->Birthday.Year);
GetStr(NULL, 0);
printf("���(�/�): ");
P->Sex=getchar();
printf("�����: ");
scanf("%i",&P->Form);
GetStr(NULL, 0);
printf("����: ");
scanf("%i",&P->FormDigit);
GetStr(NULL, 0);
printf("����� ⥫�䮭�: ");
GetStr(P->Phone,20);
}
int CSurname(PUPIL A, PUPIL B)
{
int i;
for(i=0;A.Surname[i]==B.Surname[i] && A.Surname[i]!=0;i++)
return A.Surname[i]-B.Surname[i];
}

void SortSurname(PUPIL *P,int n)
{
int i, j, min;
for(i=0;i<n-1;i++)
   {
   min=i;
   for(j=i+1;j<n;j++)
   {
   if(CSurname(P[min],P[j])>0)
   min=j;
   if(min!=i)
   pswap(&P[i],&P[min]);
   }
}
}

int CDate(PUPIL A, PUPIL B)
{
  if(A.Birthday.Year==B.Birthday.Year)
    if(A.Birthday.Month==B.Birthday.Month)
       return A.Birthday.Day-B.Birthday.Day;
    else
       return A.Birthday.Month-B.Birthday.Month;
    else
    return A.Birthday.Year-B.Birthday.Year;
}

void SortDate(PUPIL *P,int n)
{
int i, j, min;
for(i=0;i<n-1;i++)
   {
   min=i;
   for(j=i+1;j<n;j++)
   {
   if(CDate(P[min],P[j])>0)
   min=j;
   if(min!=i)
   pswap(&P[i],&P[min]);
   }
}
}

int LoadDB(char *S,PUPIL *Base, int N)
{
FILE *f;
int n;
if((f=fopen(S,"rb"))==NULL)
return 0;
n=fread(Base,sizeof(PUPIL),N,f);
fclose(f);
return n;
}