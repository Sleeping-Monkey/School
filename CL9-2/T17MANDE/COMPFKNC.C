#include "comp.h"
Comp ComSet(double a, double b)
{
Comp P;
 P.Re=a;
 P.Im=b;
return P;
}

Comp ComAdd(Comp A, Comp B)
{
return ComSet(A.Re+B.Re,A.Im+B.Im);
}

Comp ComMult(Comp A, Comp B)
{
return ComSet(A.Re*B.Re-A.Im*B.Im,A.Re*B.Im+A.Im*B.Re);
}