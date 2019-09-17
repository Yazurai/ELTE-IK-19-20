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
			fizzbuzz();
			break;
		case DIVISOR:
			divisors();
			break;
		case PERFECT:
			perfect();
			break;
		case PRIME:
			prime();
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

void fizzbuzz(){
	int n;
	readNumber(INT, &n, "Enter n: ");
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

void divisors(){
	int num;
	readNumber(INT, &num, "Enter a number: ");

	for (int i = 1; i <= num/2; i++)
	{
		if(num % i == 0){
			printf("%d, ", i);
		}
	}
	printf("\n");
}

void perfect(){
	int num;
	readNumber(INT, &num, "Enter a number: ");

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

void prime(){
	int num;
	readNumber(INT, &num, "Enter a number: ");

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
