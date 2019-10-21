#ifndef COMPLEX_H
#define COMPLEX_H

typedef struct _complex{
    double x;
    double y;
}complex;

void add(complex *a, complex *b, complex *c);
void printComplex(complex *a);

#endif