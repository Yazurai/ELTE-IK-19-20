#include <stdlib.h>

int countElem(int a, int n, int l[]){
    int sum = 0;
    for(int i = 0; i < n; i++){
        if(a == l[i]){
            sum++;
        }
    }
    return sum;
}

int *fib1(int n){
    if(n >= 0){
        if(n == 0){
            return NULL;
        } else if(n == 1){
            int *d = malloc(sizeof(int) * 1);
            d[0] = 0;
            return d;
        } else {
            int *d = malloc(sizeof(int) * n);
            d[0] = 0;
            d[1] = 1;
            for(int i = 2; i < n; i++){
                d[i] = d[i-2] + d[i-1];
            }
            return d;
        }
    } else {
        return NULL;
    }
}

int *fib2(int n, int *d){
    if(n > 0){
        if(n == 1){
            d[0] = 0;
        } else {
            d[0] = 0;
            d[1] = 1;
            for(int i = 2; i < n; i++){
                d[i] = d[i-2] + d[i-1];
            }
        }
    }
}
