#include <stdlib.h>
#include <stdio.h>
#include "1.c"
#include "3.c"

int main(){
    int a = 5;
    int list[] = {1,2,3,4,5,5,6};
    int b = countElem(a, 7, list);
    printf("%d\n", b);

    int *fibs = fib1(5);
    for(int i = 0; i < 5; i++){
        printf("%d,",fibs[i]);
    }
    free(fibs);
    printf("\n");

    int fib[10] = {0};
    fib2(sizeof(fib)/sizeof(int), fib);
    for(int i = 0; i < 10; i++){
        printf("%d,",fib[i]);
    }
    printf("\n");

    int pos[] = {1,-2,3,4,5,-6,7,-8,-9,0};
    int *news = take(3,sizeof(pos)/sizeof(int), pos);
    for(int i = 0; i < 3; i++){
        printf("%d,",news[i]);
    }
    free(news);
    printf("\n");

    int monList[] = {0,1,1,2,2,4,3,10,14,15,15};
    bool isMon = mon(sizeof(monList)/sizeof(int), monList);
    printf("the list is :%d", isMon);

    
}