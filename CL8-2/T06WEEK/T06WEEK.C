#include <stdio.h>

int Day( int D, int M, int Y )
{
  int N;

  if (M > 2)
    M++;
  else
  {
    M += 13;
    Y--;
  }
  N = (int)((Y * 36525L / 100 + M * 306 / 10 + D - 621050L) % 7);
  return N;
}

void main( void )
{
  int D, M, Y, N;

  printf("Input a day ");
  scanf("%d", &D);
  printf("Input a month ");
  scanf("%d", &M);
  printf("Input a year ");
  scanf("%d", &Y);
  N = Day(D, M, Y);
  switch(N)
  {
  case 0:  
    printf("%d.%d.%d is Monday", D, M, Y);
    break;
  case 1:
    printf("%d.%d.%d is Tuesday", D, M, Y);
    break;
  case 2:
    printf("%d.%d.%d is Wednesday", D, M, Y);
    break;
  case 3:
    printf("%d.%d.%d is Thursday", D, M, Y);
    break;
  case 4:
    printf("%d.%d.%d is Friday", D, M, Y);
    break;
  case 5:
    printf("%d.%d.%d is Saturday", D, M, Y);
    break;
  case 6:
    printf("%d.%d.%d is Sunday", D, M, Y);
    break;
  default:
    printf("Ops...");   
  }
}