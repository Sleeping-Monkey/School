#include <stdio.h>

#include "mas1.h"

#define MAX 10

void main( void )
{
  long int a[MAX];
  printf("Array is:\n");
  FillRand(a, MAX);
  PrintArray(a, MAX);
  printf("\n");
  printf("Max is %li\n", GetMaxValue(a, MAX));
  printf("Min is %li\n", GetMinValue(a, MAX));
  printf("Average is %lf\n", Average(a, MAX));
  printf("Number of even numbers with an odd amount %i\n", EvenNumberWithOddAmount(a, MAX));
  printf("Reverse array is:\n");
  Reverse(a, MAX);
  PrintArray(a, MAX);
 printf("\n");
}