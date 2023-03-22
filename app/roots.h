#ifndef ROOTS_H
#define ROOTS_H

typedef struct {
    double count_roots;
    double x1;
    double x2;
} roots;

roots decision(double a,double b,double c);
extern int val;

#endif
