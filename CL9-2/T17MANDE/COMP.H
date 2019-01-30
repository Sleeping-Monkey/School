#include <conio.h>
#include <tgrp.h>
typedef struct
{
 double Re, Im;
}Comp;
Comp ComSet(double, double);
Comp ComAdd(Comp, Comp);
Comp ComMult(Comp, Comp);
