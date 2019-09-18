#include <iostream>
#include <stdbool.h>

using namespace std;

int readNaturalNumber(string);
int factorial(int);

int main(){
    int n;
    n = readNaturalNumber("n");
    cout << n << " factorial is " << factorial(n) << endl;
    return 0;
}

int readNaturalNumber(string name) {
    int x;
    bool inputCorrect = false;
    while(!inputCorrect) {
        cout << "Please enter " << name << ": ";
        cin >> x;
        inputCorrect = !(x < 0) || (cin.fail());
        if(!inputCorrect) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Wrong input!" << endl;
        }
    }
    return x;
}

int factorial(int n) {
    int result = 1;
    for(int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}
