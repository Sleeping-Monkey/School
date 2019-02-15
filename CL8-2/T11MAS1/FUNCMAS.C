#include <stdio.h>
#include <stdlib.h>

void FillRand( long int *x, int n )
{
  int i, j;
  for (i = 0; i < n; i++)
    x[i] = rand();
}

long int GetMaxValue( long int *x, int n )
{
  int i;
  long int max1 = x[0];
  for (i = 1; i < n; i++)
    if (max1 < x[i])
      max1 = x[i];
  return max1;
}

long int GetMinValue( long int *x, int n )
{
  int i;
  long int min1 = x[0];
  for (i = 1; i < n; i++)
    if (min1 > x[i])
      min1 = x[i];
  return min1;
}

double Average( long int *x, int n )
{
  int i;
  long int sum = 0;
  for (i = 0; i < n; i++)
    sum += x[i];
  return sum/n;
}

void Reverse( long int *x, int n )
{
  int i, j;
  long int b;
  for (i = 0; i < n / 2; i++)
  {
    b = x[i];
    x[i] = x[n - i - 1];
    x[n - i - 1] = b;
  }
}

int EvenNumberWithOddAmount( long int *x, int n )
{
  int i, k = 0;
  long int sum = 0, ch;
  for (i = 0; i < n; i++)
  {
    ch = x[i];
    if (ch % 2 == 0)
    {
      while (ch != 0)
      {
        sum += ch % 10;
        ch /= 10;
      }
      if (sum % 2 == 1)
        k++;
      sum = 0;
    }
  }
  return k;
}

void PrintArray( long int *x, int n )
{
  int j;
  for (j = 0; j < n; j++)
    printf("%li ", x[j]);
}