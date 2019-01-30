static float b[7800];

void Merge(float *a, int n, int m)
{
  int k,j=m,i=0;

  for(k=0;k<n;k++)
    if(j>=n ||(i<m && a[i]<a[j]))
      b[k]=a[i++];
    else
      b[k]=a[j++];
  for(k=0;k<n;k++)
    a[k]=b[k];
}

void MergeSort(float *a, int n)
{
 int m;
    if(n>1)
      {
       m=n/2;
       MergeSort(a,m);
       MergeSort(a+m,n-m);
       Merge(a,n,m);
       }
}

void QuickSort(float *a, int n)
{
 int i=0, j=n-1;
 float p;

    if(n>1)
     {
      p=a[n/2];
      while(i<=j)
           {
            while(a[i]<p)
                 i++;
            while(a[j]>p)
                 j--;
            if(i<=j)
              {
               if(i!=j)
                 Swap(&a[i],&a[j]);
               i++;
               j--;
              }
           }
     QuickSort(a,j+1);
     QuickSort(a+i,n-i);
     }
}

void HeapCorrection(float *a, int n, int i)
{int l, r, big;
    while(1)
         {
          l=2*i+1;
          r=2*i+2;
          big=i;
          if(l<n && a[big]<a[l])
            big=l;
          if(r<n && a[big]<a[r])
            big=r;
          if(big!=i)
            {
             Swap(&a[big],&a[i]);
             i=big;
            }
          else
            return;
        }
}

void HeapSort (float *a, int n)
 {int i;
     if(n>1)
     {
     for(i=n/2-1;i>0;i--)
        HeapCorrection(a,n,i);
     for(i=n-1;i>0;i--)
        Swap(&a[0],&a[i]);
     HeapCorrection(a,i,0);
     }
}
