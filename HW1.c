#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "main.h"
#include "input.h"

typedef enum numberType {INT = 0, UINT = 1, FLOAT = 2} numberType;

typedef enum services_ {HELLO = 0, FTOC = 1, SIGN = 2, MAXIMUM = 3, FACTORIAL = 4, REMAIN = 5, MULTITABLE = 6, HCD = 7, EXIT = 8} services;

int main() {
    bool shouldExit = false;
    while(!shouldExit) {
        printf("\n Hi! Choose from the possible services by typing their number!\n Hello(0), FtoC(1), sign(2),"
               "maximum(3), factorial(4), remain(5), multiTable(6), highestCommonDivisor(7), Exit(8)\n");
        services currService;
        scanf(" %u", &currService);
        switch(currService) {
        case HELLO:
            hello();
            break;
        case FTOC:
            FtoC();
            break;
        case SIGN:
            sign();
            break;
        case MAXIMUM:
            maximum();
            break;
        case FACTORIAL:
            factorial();
            break;
        case REMAIN:
            remain();
            break;
        case MULTITABLE:
            multiTable();
            break;
        case HCD:
            hcd();
            break;
        case EXIT:
            shouldExit = true;
            break;
        default:
            printf("Wrong input, try again!\n");
        }
    }
    return 0;
}

//Reads in a float value from the console to the given float by the pointer
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

void hello() {
    printf("Hello world\n");
}

void FtoC() {
    float fahrenheit, celsius;
    readNumber(FLOAT, &fahrenheit, "Please enter a temperature in Fahrenheit: ");
    celsius = (fahrenheit - 32) * 5 / 9;
    printf("%fF = %fC!\n", fahrenheit, celsius);
}

void sign() {
    float num;
    int sign = 0;
    readNumber(FLOAT,&num, "Please enter a number: ");
    if(num < 0) {
        sign  = -1;
    } else if(num > 0) {
        sign = 1;
    }
    printf("The sign of the number is %d.\n", sign);
}

void maximum() {
    int count;
    readNumber(INT, &count, "Please enter the number of elements: ");
    float nums[count];
    for(int i = 0; i < count; i++) {
        printf("Please enter number (%d/%d): ", i, count);
        readNumber(FLOAT, &nums[i], "");
    }
    float biggest = *nums;
    for(int i = 1; i < count; i++) {
        if(biggest < *(nums + sizeof(float) * i)) {
            biggest = *(nums + sizeof(float) * i);
        }
    }
    printf("The biggest number of the %d is: %f\n", count, biggest);
}

void factorial() {
    int n, result = 0;
    readNumber(INT, &n, "Please enter a number: ");
    for(int i = 1; i < n + 1; i++) {
        result *= i;
    }
    printf("The factorial of !%d is %d\n", n, result);
}

void remain() {
    int dividend, divisor;
    readNumber(INT, &dividend, "Please enter the dividend: ");
    readNumber(INT, &divisor, "Please enter the divisor: ");
    while(dividend > divisor) {
        dividend -= divisor;
    }
    printf("The remainder is %d.\n", dividend);
}

void hcd() {
    int a, b;
    readNumber(UINT, &a, "Please enter the first number: ");
    readNumber(UINT, &b, "Please enter the second number: ");
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
    printf("The highest common divisor is %d", b);
}

void multiTable() {
    for(int y = 1; y < 11; y++) {
        for(int x = 1; x < 11; x++) {
            printf("%d * %d = %d, ", y, x, y * x);
        }
        printf("\n");
    }
}
