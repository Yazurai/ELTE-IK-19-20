#include <iostream>
#include <stdbool.h>

using namespace std;

float readNumber(string);
int quarterPlane(float, float);
int quarterPlane2(float, float);

int main(){
    float x, y;
    x = readNumber("x");
    y = readNumber("y");
    cout << "Nested ifs: " << quarterPlane(x, y) << endl;
    cout << "Else-if ifs: " << quarterPlane2(x, y) << endl;
    return 0;
}

float readNumber(string name) {
    float x;
    bool inputCorrect = false;
    while(!inputCorrect) {
        cout << "Please enter " << name << ": ";
        cin >> x;
        inputCorrect = !(cin.fail());
        if(!inputCorrect) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Wrong input!" << endl;
        }
    }
    return x;
}

int quarterPlane(float x, float y) {
    int sn;
    if(x >= 0) {
        sn = (y >= 0) ? 1 : 3;
    } else {
        sn = (y >= 0) ? 2 : 4;
    }
    return sn;
}

int quarterPlane2(float x, float y) {
    int sn;
    if(x >= 0 && y >= 0) {
        sn = 1;
    } else if(x < 0 && y >= 0) {
        sn = 2;
    } else if(x >= 0 && y < 0) {
        sn = 3;
    } else {
        sn = 4;
    }
    return sn;
}


