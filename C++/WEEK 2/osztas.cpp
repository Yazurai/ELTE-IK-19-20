#include <iostream>
#include <stdbool.h>

using namespace std;

int readNaturalNumber(string);
int mod(int, int);

int main(){
    int a = 0, b = 0;
    a = readNaturalNumber("a");
    while(b == 0) {
        b = readNaturalNumber("b");
    }
    cout << "The modulo is: " << mod(a, b) << endl;
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

int mod(int a, int b) {
    int remainder = a;
    while(remainder > b) {
        remainder -= b;
    }
    return remainder;
}
