#include "sort.h"
void AdvancedBubleSort(float *a, int n)
{
 int t, i, k=n-1;

 do
   {
    t=0;
    for(i=0;i<k;i++)
       if(a[i]>a[i+1])
         {
          Swap(&a[i], &a[i+1]);
          t=1;
         }
       k--;
   }
   while(t);
}

void SelectSort(float *a, int n)
{
 int i=0, min, j;
    for(;i<n-1;i++)
      {
       min=i;
       for(j=i+1;j<n;j++)
          if(a[min]>a[j])
            min=j;
      if(min!=i)
        Swap(&a[i], &a[min]);
     }
}

void InsertSort(float *a, int n)
{
 int i, j;
 float x;
      for(i=1;i<n;i++)
         {
          x=a[i];
          j=i-1;
          while(j>=0 && x< a[j])
               {
                a[j+1]=a[j];
                j--;
               }
         a[j+1]=x;
         }
}