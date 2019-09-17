#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "HW2.h"

typedef enum services_ {EXIT = 0, RELPRIME = 1, FIBONACCI = 2, FTTOEURO = 3, HARD = 4} services;
float const HUFTOEURATE = 0.00299728261f;

int main(){
	bool shouldExit = false;
    while(!shouldExit) {
		printf("\n Hi! Choose from the possible services by typing their number!\n Exit(0), relativePrime(1), fibonacci(2), Perfect(3), Prime(4)\n");
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
			//hard();
			break;
		default:
			printf("Wrong input, try again!\n");
		}
	}
}

void readNumber(numberType type, void *num, char *message) {
    bool inputSuccess = false;
    while(!inputSuccess) {
        while(getchar() != '\n') {
            continue;
        }

        printf("%s", message);

        int check;
        if(type == INT) {
            check = scanf(" %d", num);
        } else {
            check = scanf(" %f", num);
        }

        if(check != 0) {
            inputSuccess = (type != UINT) || (num >= 0);
        } else {
            printf("Wrong format!\n");
        }
    }
}


int hcd(int a, int b) {
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

void relativePrime(){
    int a, b;
    readNumber(INT, &a, "Enter number a: ");
    readNumber(INT, &b, "Enter number b: ");
    if(hcd(a, b) == 1){
        printf("The two numbers are relative primes.");
    } else {
        printf("The two numbers are not relative primes.");
    }
}

void fibonacciCheck(){
    int a = 1, b = 1, n;
    readNumber(INT, &n, "Enter number a: ");
    while(b < n){
        int c = a + b;
        a = b;
        b = c;
    }
    if(b == n) {
        printf("%d is a Fibonacci number.", n);
    } else {
        printf("%d is not a Fibonacci number.", n);
    }
}

void ftToEuro(){
    int n;
    readNumber(INT, &n, "Please enter an amount in HUF");
    for(int i = 1; i <= n; i++){
        printf("%d HUF is %.03f EUR.\n", n, n * HUFTOEURATE);
    }
}

void hard(){

}
