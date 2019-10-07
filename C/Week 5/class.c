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

char* concatString(int aLength, char *a, int bLength, char *b, char *c){
    for(int i = 0; i < aLength; i++){
        c[i] = a[i];
    }
    for(int i = 0; i < bLength; i++){
        c[aLength + i] = b[i];
    }
    return c;
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
    char d[] = "world!";
    char *e = malloc(sizeof(char) * 13);
    e = concatString(6,c,6,d,e);
    printf("%s\n", e);
    free(e);

    char blabla[]= "alma";
    printf("%d", (int)(sizeof(blabla)/sizeof(char)));
}
