#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h> 

int *take(int dc, int lc, int l[]){
    int *d = malloc(sizeof(int) * dc);
    int counter = 0;
    for(int i = 0; i < lc && counter < dc; i++){
        if(l[i] > 0){
            d[counter] = l[i]; 
            counter++;
        }
    }
    if(counter == dc){
        return d;
    } else {
        free(d);
        return NULL;
    }
}

bool mon(int n, int l[]){
    char state = 0;
    int last = l[0];
    for(int i = 1; i < n; i++){
        if(state == 0){
            if(l[i] > last){
                last = l[i];
                state = 1;
            } else if(l[i] > last){
                last = l[i];
                state = -1;
            } 
        } else if(state == 1){
            if(l[i] >= last){
                last = l[i];
            } else {
                return false;
            }
        } else {
            if(l[i] <= last){
                last = l[i];
            } else {
                return false;
            }
        }
    }
    return true;
}