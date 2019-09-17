#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Exercise2.h"
#include "input.h"

typedef enum services_ {EXIT = 0, FIZZBUZZ = 1, DIVISOR = 2, PERFECT = 3, PRIME = 4} services;

int main(){
	bool shouldExit = false;
    while(!shouldExit) {
		printf("\n Hi! Choose from the possible services by typing their number!\n Exit(0), FizzBuzz(1), divisors(2), Perfect(3), Prime(4)\n");
		services currService;
		scanf(" %u", &currService);
		switch(currService) {
		case EXIT:
			shouldExit = true;
			break;
		case FIZZBUZZ:
		    int n;
		    readNumber(INT, &n, "Enter n: ");
			fizzbuzz(n);
			break;
		case DIVISOR:
		    int num;
            readNumber(INT, &num, "Enter a number: ");
			divisors(num);
			break;
		case PERFECT:
		    int num;
            readNumber(INT, &num, "Enter a number: ");
			perfect(num);
			break;
		case PRIME:
		    int num;
            readNumber(INT, &num, "Enter a number: ");
			prime(num);
			break;
		default:
			printf("Wrong input, try again!\n");
		}
	}
}

void fizzbuzz(int n){
	for (int i = 1; i <= n; i++)
	{
		if(i % 3 != 0 && i % 5 != 0){
			printf("%d", i);
		} else {
			if(i % 3 == 0){
				printf("fizz");
			}
			if(i % 5 == 0){
				printf("buzz");
			}
		}
		printf("\n");
	}
}

void divisors(int num){
	for (int i = 1; i <= num/2; i++)
	{
		if(num % i == 0){
			printf("%d, ", i);
		}
	}
	printf("\n");
}

void perfect(int num){
	int sum = 0;
	for (int i = 1; i <= num/2; i++){
		if(num % i == 0){
			sum += i;
		}
	}

	if(sum == num){
		printf("The number is a perfect! \n");
	} else  {
		printf("The number is not a perfect! \n");
	}
}

void prime(int num){
	bool isPrime = true;
	for (int i = 2; i <= num/2; i++){
		if(num % i == 0){
			isPrime = false;
		}
	}
	if(isPrime){
		printf("The number is a prime! \n");
	} else  {
		printf("The number is not a prime! \n");
	}
}
