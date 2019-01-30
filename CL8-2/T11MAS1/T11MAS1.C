#include <stdio.h>
#define MAX 10
#include "mas1.h"
void main(void)  3
{long int a[MAX];
 printf("Массив:\n");
  sluch(a, MAX);
  vuv(a, MAX);
 printf("\n");
 printf("Максимум %li\n", maxu(a, MAX));
 printf("Минимум %li\n", mini(a, MAX));
 printf("Среднее арифм %lf\n", srar(a, MAX));
 printf("Количество четных чисел с нечетной суммой %i\n", cht(a, MAX));
 printf("Перевернутый массив:\n");
  per(a, MAX);
  vuv(a, MAX);
 printf("\n");
}