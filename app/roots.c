#include <stdio.h>
#include "roots.h"

roots decision(long a,long b,long c){
    roots rez;
    long sqr_d, r1, r2;

    sqr_d =(b*b - 4*a*c) * 0.5;
    r1 = (-b + sqr_d) / (2*a);
    r2 = (-b - sqr_d) / (2*a);
    rez.x1 = r1;
    rez.x2 = r2;

    return rez;
}

