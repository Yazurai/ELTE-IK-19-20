#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "HW2.h"

/* A list of constants, good to have them here.(#define 'NAME' 'VALUE')
 * It helps with avoiding magic numbers(random literals, especially numbers).
 */
#define HUFTOEURATE 0.00299728261
#define Z 3
#define I 1
#define M 4

/* An enum to label all the different exercises to numbers. Enums usually are not necessary, but when used right,
 * they help the readability of the code (see the switch statement at line 29, imagine if all the cases were numbers).
 * Enums can be made in the form of enum enumName {VALUE1, VALUE2, VALUE3}; Automatically numbered from 0,1,2...
 * Normally, to make an enum variable, you would need to type enum enumName varName;
 * Typedef makes it so you can use enumName as if it was like an actual type (for example line 27)
 */
typedef enum services_ {EXIT = 0, RELPRIME = 1, FIBONACCI = 2, FTTOEURO = 3, CYCLE = 4} services;

int main() {
    bool shouldExit = false;
    while(!shouldExit) {
        printf("\nHi! Choose from the possible services by typing their number!\n"
               "Exit(0), relativePrime(1), fibonacci(2), Perfect(3), cycleDetection(4)\n");
        services currService;
        while(getchar() != '\n') {} //This clears the buffer (if you enter multiple inputs, scanf wont clear any of them and subsequent scanf will get stuck)
        scanf(" %u", &currService);
        switch(currService) {       //The main function usually should be really compact. Might want to consider moving this out to its own function. I'm too lazy for that
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
        case CYCLE:
            cyclefunction(&exampleFunc);
            break;
        default:
            printf("Wrong input, try again!\n");
        }
    }
}

/* Reusing the same Euclidean algorithm based function from HW1
*/
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

void relativePrime() {
    int a, b;
    bool inputCorrect = false;                      //This is the basic error chacking for scanf input
    while(!inputCorrect){                           //Keep retrying until we get a correct input
        while(getchar() != '\n') {}                 //Clear the buffer, avoids when the previous input consisted of multiple wrong inputs
        printf("Please enter two numbers: ");       //Print a message to the user
        inputCorrect = scanf(" %d %d", &a, &b) == 2;//Read in using scanf and set the loop escape boolean accordingly
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
        printf("%d HUF is %.03f EUR. \n", n, n * HUFTOEURATE);  //Notice the formatting (%.03f), we went through this during the class.
                                                                //Also, the use of the defined constant HUFTOEURATE, readable than 0.00299728261
    }
}

/*This is the big boi for this week. The specification for this exercise was a little bit confusing for me.
 *I interpreted as the algorithm being able to handle any sort of function. This is done with a pointer to a function in the function arguments.
 *This way, you can pass in any function that takes an int and returns an int.
 *
 *The general algorithm is very simple and basic. You start from i=x0 and keep going, and for each i you compare it to every previous x (x<i) and see if any has the same value.
 *
 *This function will get really inefficient in the long run, especially if the function given has a long runtime. Another fairly simple option would be to store the values that have already come up.
 *The only issue is that the basic array in c need it's size to be predefined. You could make a list data-structure, but that is most likely out of the scope for this month.
 *I will include it down below anyway.
 */
void cyclefunction(int (*func)(int)) {
    int startValue;
    bool inputCorrect = false;
    while(!inputCorrect){
        while(getchar() != '\n') {}
        printf("Please enter a number: ");
        inputCorrect = scanf(" %d", &startValue) == 1;
    }
    int cycleStart, cycleLength;
    bool foundCycle = false;
    for(int currX = 0; !foundCycle; currX++){                   //In case you didn't notice, note the unusual conditionals in the for cycle
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

/*-----------------------------------------------------------------------------------------
 *-----------------------------------------------------------------------------------------
 *This is a partial linked list data structure that uses pointers to reference the next node.
 *This way you only need the first node to access the rest of it.
 *The list heavily relies on pointers, dynamic memory allocation so it adds a whole bunch of extra stuff we haven't gone through yet during classes.
 *However, writing data structure like these are a great practice for understanding pointers and dynamyc mem allocation.
 *
 *  !!! WARNING !!!
 *    -This code is UNTESTED and has NOT BEEN RUN even once. It's just there to show you a concept of something a lil bit more complex.
 */

typedef struct node{
    int elem;
    struct node *next;
}node;

node* initializeList(int elem){
    node *newList = malloc(sizeof(node));
    if(newList != NULL){
        newList->elem = elem;
    }
}

bool addToList(node *list, int elem){
    node *currNode = list;
    while(currNode->next != NULL){
        currNode = currNode->next;
    }
    node *newNode = malloc(sizeof(node));
    if(newNode == NULL) {
        return false;
    } else {
        newNode->elem = elem;
        currNode->next = newNode;
        return true;
    }
}

bool findInList(node *list, int elem){
    node *currNode = list;
    while(currNode->next != NULL){
        if(currNode->elem == elem){
            return true;
        }
    }
    return false;
}

void clearList(node *list){
    node *currNode = list;
    while(currNode->next != NULL){
        node *nextNode = currNode->next;
        free(currNode);
        currNode = nextNode;
    }
}

void cyclefunction2(int (*func)(int)) {
    int startValue;
    bool inputCorrect = false;
    while(!inputCorrect){
        while(getchar() != '\n') {}
        printf("Please enter a number: ");
        inputCorrect = scanf(" %d", &startValue) == 1;
    }
    int cycleStart, cycleLength;
    node *list = initializeList(getCycleElem(func, startValue, 0));        //Add the first element
    bool foundCycle = false;
    for(int currX = 1; !foundCycle; currX++){
        int currFuncVal = getCycleElem(func, startValue, currX);            //You can notice that we only need to evaluate every f(x) only once
        if(findInList(list, currFuncVal)) {                                 //Essentially, this way we reduced every function execution to a single if check
            foundCycle = true;
        } else {
            addToList(list, currFuncVal);
        }
    }
    printf("The cycle starts at %d and has a length of %d. \n", cycleStart, cycleLength);
}
