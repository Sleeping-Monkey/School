void FillRand(float *a, int n)
{
 int i=0;
    for(;i<n;i++)
       a[i]=rand()/100.0 - 150.0;
}

void FillIncr(float *a, int n)
{
 int i=0;
    for(;i<n;i++)
       a[i]=(i+1)*3.083;
}

void FillDeor(float *a, int n)
{
 int i=0;
    for(;i<n;i++)
       a[i]=(n-i)*3.083;
}

void FillEqual(float *a, int n)
{
 int i;
 float x;
    x=rand() /50.0;
    for(i=0;i<n;i++)
       a[i]=x;
}

void Swap(float *x, float *y)
{
 float tmp;
       tmp=*x;
       *x=*y;
       *y=tmp;
}

void Almost(float *a, int n)
{
 int i;
 FillIncr(a, n);
 for(i=0;i<n/20;i++)
 Swap(&a[rand()%n], &a[rand()%n]);
}

int Cheak(float *a, int n)
{
 int i=0;
    for(;i<n-1;i++)
       if(a[i]>a[i+1])
         return 0;
 return 1;
}