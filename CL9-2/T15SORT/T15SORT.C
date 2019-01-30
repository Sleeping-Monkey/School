#include "sort.h"

void main (void)
{
 static float a[MAX];
 int si, fi;
 double t;
    void (*Sort[])(float *a, int n)={AdvancedBubleSort, SelectSort, InsertSort, MergeSort, QuickSort, HeapSort};
    void (*Fill[])(float *a, int n)={FillRand, FillRand, FillDeor, FillEqual};
    char (*Sname[])={"Пузырек","Выбор","Вставка","Слияние","Быстрая","Кучей"};
         for(si=0;si<sizeof(Sort)/sizeof(Sort[0]);si++)
            {
             printf("%s\n", Sname[si]);
             for(fi=0;fi<sizeof(Fill)/sizeof(Fill[0]);fi++)
                {
                 Fill[fi](a,MAX);
                 t=clock();
                 Sort[si](a,MAX);
                 t=clock()-t;
                 if(Cheak(a,MAX))
                   printf("%lf\n", t/(double)CLOCKS_PER_SEC);
                 else
                   printf("Fail!!!\n");
                }
            }
}