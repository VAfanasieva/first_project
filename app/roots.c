#include <stdio.h>
#include <math.h>
#include "roots.h"

roots decision(double a,double b,double c){
    roots rez;
    double d;

    if(a == 0){
        rez.x1 = (-c) / b;
        rez.count_roots = 1;
        return rez;
    }

    d = b*b - 4*a*c;

    if(d < 0){
        rez.count_roots = 0;
        return rez;
    }
    if(d == 0){
        rez.count_roots = 1;
        rez.x1 = (-b) / (2 * a);
        return rez;
    }
    rez.count_roots = 2;
    rez.x1 = (-b + sqrt(d)) / (2 * a);
    rez.x2 = (-b - sqrt(d)) / (2 * a);
    return rez;
}

