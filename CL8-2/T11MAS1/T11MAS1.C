#include <stdio.h>
#define MAX 10
#include "mas1.h"
void main(void)  3
{long int a[MAX];
 printf("���ᨢ:\n");
  sluch(a, MAX);
  vuv(a, MAX);
 printf("\n");
 printf("���ᨬ� %li\n", maxu(a, MAX));
 printf("������ %li\n", mini(a, MAX));
 printf("�।��� ��� %lf\n", srar(a, MAX));
 printf("������⢮ ���� �ᥫ � ���⭮� �㬬�� %i\n", cht(a, MAX));
 printf("��ॢ����� ���ᨢ:\n");
  per(a, MAX);
  vuv(a, MAX);
 printf("\n");
}