#include "a.h"
void GetStr(char *s, int n)
{
 int i=0;
 char ch;
 while((ch=getchar())!='\n')
      if(i<n-1 && s!=NULL)
        s[i++]=ch;
 if(i<n && s!=NULL)
    s[i]='\0';
}
int LenStr(char *s)
{
 int i=0;
 while(*s++!=0)
 i++;
 return i;
}

int Colvb(char *s)
{
 int i=0;
 while(*s!='\0')
      {
       if((*s>='A' && *s<='Z') || (*s>='a' && *s<='z'))
         i++;
       *s++;
      }
 return i;
}

int Colvch(char *s)
{
 int i=0;
 while(*s!='\0')
      {
       if((*s>='0' && *s<='9'))
         i++;
       *s++;
      }
 return i;
}

int Sim(char *s, int n)
{int i=0, j=n-1;
 while(i<j)
      if(s[i]==s[j])
        {
         i++;
         j--;
        }
      else
      return 0;
 return 1;

}

int Colvc(char *s)
{
 int i=0;
 if(*s!='\n' && *s!=' ')
   {
    i++;
    *s++;
   }
 while(*s!='\0')
      {
       if(*s!=' ' && *s!='\n')
         {
          *s--;
          if(*s==' ' || *s=='\n')
            i++;
          *s++;
         }
       *s++;
      }

 return i;
}
int Pal(char *s)
{int i=0, l=0, big, end;
  while(s[i])
     {
      while(s[i]==' ')
        i++;
      if(s[i]!='\0')
        {
          l++;
          big=i;
         while(s[i]!=' ' && s[i]!='\0')
           i++;
          end=i-1;
         while(big<end)
           if(s[big]==s[end])
            {
             big++;
             end--;
            }
           else
            {
             l--;
             break;
            }
        }
     }
  return l;
}

int Sum(char *s)
{int sum=0, i=0, ch=0;
 while(s[i])
 {
  while(s[i]==' ')
        i++;
         while(s[i]!=' ' && s[i]!='\0')
              {
               if(s[i]<='9' && s[i]>='0')
                 ch=ch*10+(s[i]-'0');
               i++;
              }
        sum+=ch;
        ch=0;
  }
  return sum;
}

void Bez(char *s)
{
int i=0, k=0, n;
  while(s[i])
   {
    while(s[i]!=' ' && s[i]!='\0')
         i++;
    n=i;
    if(s[i]=='\0')
      break;
    while(s[i]==' ')
        i++;
    k=i;
    while(s[i])
     {
     s[i-k+n]=s[i];
     s[i]=' ';
     i++;
     }
     i=0;
   }
}

