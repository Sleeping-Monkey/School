#include <stdio.h>
#include <conio.h>
#define MAX 50
typedef struct
{
int Day, Month, Year;
}DATE;
typedef struct
{
char Surname[20], Name[15];
DATE Birthday;
char Sex;
int Form;/*Номер класса*/
char FormDigit;/*Цифра\Буква класса*/
char Phone[15];
}PUPIL;
void GetStr(char *, int);
void pswap(PUPIL *, PUPIL *);
void ReadPupil(PUPIL *);
int CSurname(PUPIL , PUPIL );
void SortSurname(PUPIL *,int);
int CDate(PUPIL , PUPIL );
void SortDate(PUPIL *,int);
int LoadDB(char *,PUPIL *, int);