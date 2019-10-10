#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int getLength(char *text) {
    int count = 0;
    while(*text != '\0') {
        text += sizeof(char);
        count++;
    }
    return count;
}

//2 ?????????????????

bool cmpArray(int elemCount, int *a, int *b) {
    for(int i = 0; i < elemCount; i++) {
        if(*a != *b) {
            return false;
        }
        a++, b++;
    }
    return true;
}

void concatString(int aLength, char *a, int bLength, char *b, char *c){
    aLength--; bLength--; //get rid of the '\0' at the end of both
    for(int i = 0; i < aLength; i++){
        c[i] = a[i];
    }
    for(int i = 0; i < bLength; i++){
        c[aLength + i] = b[i];
    }
    c[aLength+bLength] = '\0';
}

void createCopy(int *origin,int **copy){
    for(int i = 0; i < 5; i++){
        *copy = origin;
        copy++, origin++;
    }
}

int main() {
    printf("%d \n", getLength("abcdef"));

    int a[5] = {1,2,3,4,5};
    int b[5] = {1,2,3,4,5};
    if(cmpArray(5, a, b)){
        printf("equal \n");
    }else{
        printf("not equal \n");
    }

    char c[] = "hello ";
    int sizeC = sizeof(c)/sizeof(c[0]);
    char d[] = "world!";
    int sizeD = sizeof(d)/sizeof(d[0]);
    char e[sizeC + sizeD - 1];
    concatString(sizeC,c,sizeD,d,e);
    printf("%d\n", sizeof(e));
    printf("%s\n", e);

    int f[5] = {1,2,3,4,5};
    int *cpy[5];
    createCopy(f, cpy);
    printf("origin: %d, cpy: %d\n", f[0], *cpy[0]);
    f[0] = 10;
    printf("origin: %d, cpy: %d\n", f[0], *cpy[0]);
}
