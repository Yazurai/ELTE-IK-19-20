#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "HW2.h"

#define HUFTOEURATE 0.00299728261
#define Z 3
#define I 1
#define M 4

typedef enum services_ {EXIT = 0, RELPRIME = 1, FIBONACCI = 2, FTTOEURO = 3, HARD = 4} services;

int main() {
    bool shouldExit = false;
    while(!shouldExit) {
        printf("\nHi! Choose from the possible services by typing their number!\n"
               "Exit(0), relativePrime(1), fibonacci(2), Perfect(3), cycleDetection(4)\n");
        services currService;
        scanf(" %u", &currService);
        switch(currService) {
        case EXIT:
            shouldExit = true;
            break;
        case RELPRIME:
            relativePrime();
            break;
        case FIBONACCI:
            fibonacciCheck();
            break;
        case FTTOEURO:
            ftToEuro();
            break;
        case HARD:
            hard(&exampleFunc);
            break;
        default:
            printf("Wrong input, try again!\n");
        }
    }
}

int hcd(int a, int b) { //Reusing the same Euclidean function from HW1
    if(a < b) {
        int oldA = a;
        a = b;
        b = oldA;
    }
    int remainder = a % b;
    while (remainder > 0) {
        a = b;
        b = remainder;
        remainder = a % b;
    }
    return b;
}

void relativePrime() {
    int a, b;
    bool inputCorrect = false;
    while(!inputCorrect){
        while(getchar() != '\n') {}
        printf("Please enter two numbers: ");
        inputCorrect = scanf(" %d %d", &a, &b) == 2;
    }
    if(hcd(a, b) == 1) {
        printf("The two numbers are relative primes. \n");
    } else {
        printf("The two numbers are not relative primes. \n");
    }
}

void fibonacciCheck() {
    int a = 1, b = 1, n;
    bool inputCorrect = false;
    while(!inputCorrect){
        while(getchar() != '\n') {}
        printf("Please enter a number: ");
        inputCorrect = scanf(" %d", &n) == 1;
    }
    while(b < n) {
        int c = a + b;
        a = b;
        b = c;
    }
    if(b == n) {
        printf("%d is a Fibonacci number. \n", n);
    } else {
        printf("%d is not a Fibonacci number. \n", n);
    }
}

void ftToEuro() {
    int n;
    bool inputCorrect = false;
    while(!inputCorrect){
        while(getchar() != '\n') {}
        printf("Please enter a number: ");
        inputCorrect = scanf(" %d", &n) == 1;
    }
    for(int i = 1; i <= n; i++) {
        printf("%d HUF is %.03f EUR. \n", n, n * HUFTOEURATE);
    }
}

void hard(int (*func)(int)) {
    int startValue;
    bool inputCorrect = false;
    while(!inputCorrect){
        while(getchar() != '\n') {}
        printf("Please enter a number: ");
        inputCorrect = scanf(" %d", &startValue) == 1;
    }
    int cycleStart, cycleLength;
    bool foundCycle = false;
    for(int currX = 0; !foundCycle; currX++){
        for(int x = 0; x < currX && !foundCycle; x++){
            if(getCycleElem(func, startValue, x) == getCycleElem(func, startValue, currX)){
                cycleStart = x;
                cycleLength = currX - x;
                foundCycle = true;
            }
        }
    }
    printf("The cycle starts at %d and has a length of %d. \n", cycleStart, cycleLength);
}

int getCycleElem(int (*func)(int), int startValue, int x) {
    int result = startValue;
    for(int i = 0; i < x; i++){
        result = func(result);
    }
    return result;
}

int exampleFunc(int x){
    return (Z * x + I) % M;
}
