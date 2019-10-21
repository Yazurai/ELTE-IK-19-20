#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "complex.h"

int main(){
    complex a = {2.3, 3};
    complex b = {5.7, 7.23};
    complex *c = malloc(sizeof(complex));

    add(&a, &b, c);
    printComplex(c);
    
    free(c);
    return 0;
}

void add(complex *a, complex *b, complex *c){
    c->x = a->x + b->x;
    c->y = a->y + b->y;
}

void printComplex(complex *a){
    printf("%.3f + %.3f*i", a->x, a->y);
}
