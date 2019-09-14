#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "main.h"

typedef enum services_ {HELLO = 0, FTOC = 1, SIGN = 2, MAXIMUM = 3, FACTORIAL = 4, REMAIN = 5, MULTITABLE = 6, HCD = 7, EXIT = 8} services;

int main() {
    bool shouldExit = false;
    while(!shouldExit) {
        printf("\nHi! Choose from the possible services by typing their number!\n Hello(0), FtoC(1), sign(2),"
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
bool readFloat(float *num, char *message) {
    printf("%s", message);
    int check = scanf(" %f", num);
    if(check != 0) {
        return true;
    } else {
        printf("Rossz formatum!\n");
        return false;
    }
}

//Reads in an int (could merge with float method)
bool readInt(int *num, char *message) {
    printf("%s", message);
    int check = scanf(" %d", num);
    if(check != 0) {
        return true;
    } else {
        printf("Rossz formatum!\n");
        return false;
    }
}

void hello() {
    printf("[HELLO]\n");
    printf("Hello world\n");
}

void FtoC() {
    float farenheit, celsius;
    printf("[FAHRENHEIT TO CELCIUS]\n");
    if(readFloat(&farenheit, "Please enter a temperature in Fahrenheit: ")) {
        celsius = (farenheit - 32) * 5 / 9;
        printf("%fF = %fC!\n", farenheit, celsius);
    }
}

void sign() {
    float num;
    printf("[SIGN]\n");
    if(readFloat(&num, "Please enter a number: ")) {
        if(num < 0) {
            printf("The sign of the number is -1.\n");
        } else {
            if(num > 0) {
                printf("The sign of the number is 1.\n");
            } else {
                printf("The sign of the number is 0.\n");
            }
        }
    }
}

//Easily expandable to any number of elements
void maximum() {
    int count;
    printf("[MAXIMUM]\n");
    if(!readInt(&count, "Please enter the number of elements: ")) {
        return;
    }
    float nums[count];
    for(int i = 0; i < count; i++) {
        printf("Please enter number (%d/%d): ", i, count);
        if(!readFloat(nums + sizeof(float) * i, "")) {
            return;
        }
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
    int n, sum = 0;
    printf("[FACTORIAL]\n");
    if(readInt(&n, "Please enter a number: ")) {
        for(int i = 1; i < n + 1; i++) {
            sum += i;
        }
        printf("The factorial of !%d is %d\n", n, sum);
    }
}

void remain() {
    printf("[REMAINDER]\n");
    int dividend, divisor;
    printf("Please enter the dividend: ");
    if(scanf(" %d", &dividend) == 0) {
        return;
    }
    printf("Please enter the divisor: ");
    if(scanf(" %d", &divisor) == 0) {
        return;
    }
    while(dividend > 0) {
        dividend -= divisor;
    }
    printf("The remainder is %d.\n", divisor + dividend);
}

void hcd() {
    int a, b;
    if(!readInt(&a, "Please enter the first number!")){
        return;
    }
    if(!readInt(&b, "Please enter the first number!")){
        return;
    }
    if(a < 0 || b < 0) {
        return;
    }
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
    printf("[MULTIPLICATION TABLE]\n");
    for(int y = 1; y < 11; y++) {
        for(int x = 1; x < 11; x++) {
            printf("%d * %d = %d, ", y, x, y * x);
        }
        printf("\n");
    }
}



