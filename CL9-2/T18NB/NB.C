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
printf("Фамилия: ");
GetStr(P->Surname,20);
printf("Имя: ");
GetStr(P->Name,15);
printf("Дата Рождения\n     День: ");
scanf("%i",&P->Birthday.Day);
GetStr(NULL, 0);
printf("\n     Месяц: ");
scanf("%i",&P->Birthday.Month);
GetStr(NULL, 0);
printf("\n     Год: ");
scanf("%i",&P->Birthday.Year);
GetStr(NULL, 0);
printf("Пол(М/Ж): ");
P->Sex=getchar();
printf("Класс: ");
scanf("%i",&P->Form);
GetStr(NULL, 0);
printf("Цифра: ");
scanf("%i",&P->FormDigit);
GetStr(NULL, 0);
printf("Номер телефона: ");
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