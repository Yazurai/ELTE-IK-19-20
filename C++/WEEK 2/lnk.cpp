#include <iostream>
#include <stdbool.h>

using namespace std;

int readPositiveNumber(string);
int hcd(int, int);

int main(){
    int a = 0, b = 0;
    a = readPositiveNumber("a");
    b = readPositiveNumber("b");
    cout << "The highest common divisor is: " << hcd(a, b) << endl;
    return 0;
}

int hcd(int a, int b){
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
    int divisor = b;
    return divisor;
}

int readPositiveNumber(string name) {
    int x;
    bool inputCorrect = false;
    while(!inputCorrect) {
        cout << "Please enter " << name << ": ";
        cin >> x;
        inputCorrect = !(x <= 0) || (cin.fail());
        if(!inputCorrect) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Wrong input!" << endl;
        }
    }
    return x;
}
