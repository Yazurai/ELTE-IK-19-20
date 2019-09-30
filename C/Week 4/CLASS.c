#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "CLASS.h"

int main(){
	printPointerAddress();
	int *a = malloc(sizeof(int));
	int *b = malloc(sizeof(int));
	scanf("%d", a);
	scanf("%d", b);
	printf("A is:%d, B is:%d\n", *a, *b);
	printf("Sum is: %d\n", sum(a, b));
	printf("Multiply is: %d\n", multiply(a, b));
	free(a);
	free(b);
	
	float *c = malloc(sizeof(float));
	float *d = malloc(sizeof(float));
	scanf("%f", c);
	scanf("%f", d);
	printf("A is:%f, B is:%f\n", *c, *d);
	swap(c, d);
	printf("After swap, A is:%f, B is:%f\n", *c, *d);
	free(c);
	free(d);
	
	getArray();
	readArray();
}

int sum(int *a, int *b){
	return *a + *b;
}

int multiply(int *a, int *b){
	return *a * *b;
}

void swap(float *a, float *b){
	float temp = *a;
	*a = *b;
	*b = temp;
}

void printPointerAddress(){
	int variable = 0;
	void *pointer = &variable;
	printf("%p\n", pointer);
}

void printArray(int count, int array[]){
	printf("\n");
	for (int i = 0; i < count; i++)
	{
		printf("%d\n", array[i]);
	}
	printf("\n");
}

void getArray(){
	int array2[10] = {0,0,0,0,0,0,0,0,0,0};
	int *array3 = (int *)malloc(sizeof(int)*10);
	for (int i = 0; i < 10; i++)
	{
		array3[i] = 0;
	}
	int *array4 = (int *)malloc(sizeof(int)*10);
	for (int i = 0; i < 10; i++)
	{
		*(array4 + i * sizeof(int)) = 0;
	}
	printArray(10, array2);
	printArray(10, array3);
	printArray(10, array4);
	free(array3);
	free(array4);
}

void reverseArray(int count, int array[]){
	int reversedArray[count];
	for (int i = 0; i < count; i++)
	{
		reversedArray[count - 1 - i] = array[i];
	}
	printArray(5, reversedArray);
}

void readArray(){
	int *newArray = (int *)malloc(sizeof(int)*5);
	int nextElem;
	for (int i = 0; i < 5; i++)
	{
		scanf("%d", &nextElem);
		*(newArray + i * sizeof(int)) = nextElem;
	}
	printArray(5, newArray);
	reverseArray(5, newArray);
	free(newArray);
}


