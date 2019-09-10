#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

enum services {HELLO = 0, FTOC = 1, SIGN = 2, MAXIMUM = 3, FACTORIAL = 4, REMAIN = 5, MULTITABLE = 6, EXIT = 7};

int main()
{
    bool shouldExit = false;
    while(!shouldExit)
    {
        printf("Hi! Choose from the possible services by typing their number!\n Hello(0), FtoC(1), sign(2),"
               "maximum(3), factorial(4), remain(5), multiTable(6), Exit(7)\n");
        enum services currService;
        scanf(" %d", &currService);
        switch(currService)
        {
        case HELLO:
            hello(); break;
        case FTOC:
            FtoC(); break;
        case SIGN:
            sign(); break;
        case MAXIMUM:
            maximum(); break;
        case FACTORIAL:
            factorial(); break;
        case REMAIN:
            remain(); break;
        case MULTITABLE:
            multiTable(); break;
        case EXIT:
            shouldExit = true; break;
        default:
            printf("Wrong input, try again!\n");
        }
    }
    return 0;
}

//Reads in a float value from the console to the given float by the pointer
bool readFloat(float *num)
{
    int check = scanf(" %f", num);
    if(check != 0)
    {
        return true;
    }
    else
    {
        printf("Rossz formatum!\n");
        return false;
    }
}

//Reads in an int (could merge with float method)
bool readInt(int *num)
{
    int check = scanf(" %d", num);
    if(check != 0)
    {
        return true;
    }
    else
    {
        printf("Rossz formatum!\n");
        return false;
    }
}

void hello()
{
    printf("[HELLO]\n");
    printf("Hello world\n");
}

void FtoC()
{
    printf("[FAHRENHEIT TO CELCIUS]\n");
    printf("Please enter a temperature in Fahrenheit: ");
    float farenheit, celsius;
    if(readFloat(&farenheit))
    {
        celsius = (farenheit - 32) * 5 / 9;
        printf("%fF = %fC!\n", farenheit, celsius);
    }
}

void sign()
{
    printf("[SIGN]\n");
    printf("Please enter a number: ");
    float num;
    if(readFloat(&num))
    {
        if(num < 0)
        {
            printf("The sign of the number is -1.\n");
        }
        else
        {
            if(num > 0)
            {
                printf("The sign of the number is 1.\n");
            }
            else
            {
                printf("The sign of the number is 0.\n");
            }
        }
    }
}

//Easily expandable to any number of elements
void maximum()
{
    printf("[MAXIMUM]\n");
    printf("Please enter the number of elements.")
    int count;
    if(readInt(&count)) 
    {
		return;
	}
    float nums[count];
    int numCount = 0;
    for(int i = 0; i < count; i++)
    {
        printf("Please enter number (%d/%d): ", i, count);
        if(!readFloat(nums + sizeof(float) * i))
        {
			return;
        }
    }
    float biggest = *nums;
    for(int i = 1; i < 3; i++)
    {
        if(biggest < *(nums + sizeof(float) * i))
        {
            biggest = *(nums + sizeof(float) * i);
        }
    }
    printf("The biggest number of the %d is: %f\n", numCount, biggest);
}

void factorial()
{
    printf("[FACTORIAL]\n");
    printf("Please enter a number: ");
    int n, sum = 0;
    if(readInt(&n))
    {
        for(int i = 1; i < n + 1; i++)
        {
            sum += i;
        }
        printf("The factorial of !%d is %d\n", n, sum);
    }
}

void remain()
{
    printf("[REMAINDER]\n");
    int dividend, divisor;
    printf("Please enter the dividend: ");
    if(scanf(" %d", &dividend) == 0)
    {
        return;
    }
    printf("Please enter the divisor: ");
    if(scanf(" %d", &divisor) == 0)
    {
        return;
    }
    while(dividend > 0)
    {
        dividend -= divisor;
    }
    printf("The remainder is %d.\n", divisor + dividend);
}

void multiTable()
{
    printf("[MULTIPLICATION TABLE]\n");
    for(int y = 1; y < 11; y++)
    {
        for(int x = 1; x < 11; x++)
        {
            printf("%d * %d = %d, ", y, x, y * x);
        }
        printf("\n");
    }
}



