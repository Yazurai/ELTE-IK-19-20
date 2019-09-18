#include <iostream>
#include <stdbool.h>

#define V 24*60*60
#define GAPYEAR [31,28,31,30,31,30,31,31,30,31,30,31]
#define NOTGAPYEAR [31,29,31,30,31,30,31,31,30,31,30,31]

using namespace std;

typedef struct date{
    int year;
    int month;
    int day;
    int hours;
    int minutes;
    int seconds;
} date;

float readNumber(bool isNatural, string name) {
    float x;
    bool isIdiot = true;
    while(isIdiot) {
        cout << "Please enter " << name << ": ";
        cin >> x;
        if(isNatural){
            isIdiot = (x < 0) || (cin.fail());
        } else {
            isIdiot = (cin.fail());
        }
        if(isIdiot) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Wrong input!" << endl;
        }
    }
    return x;
}

int siknegyed() {
    float x, y;
    int sn;
    x = readNumber(false, "x");
    y = readNumber(false, "y");

    if(x >= 0) {
        if(y >= 0) {
            sn = 1;
        } else {
            sn = 3;
        }
    } else {
        if(y >= 0) {
            sn = 2;
        } else {
            sn = 4;
        }
    }
    return sn;
}

int siknegyed2() {
    float x, y;
    int sn;
    x = readNumber(false, "x");
    y = readNumber(false, "y");
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

int factorial() {
    int n, result = 1;
    n = (int)readNumber(true, "n");
    for(int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

int mod() {
    int a = 0, b = 0;
    while(b == 0) {
        a = (int)readNumber(true, "a");
        b = (int)readNumber(true, "b");
    }
    int remainder = a;
    while(remainder > b) {
        remainder -= b;
    }
    return remainder;
}

bool isSkipYear(int year){
    return (year % 4 == 0) && ((year % 100 != 0) || (year % 400 == 0));
}

void leftUntilYearEnd(){
    date d = {0,0,0,0,0,0}, rem = {0,0,0,0,0,0};

    cout << "Enter the time int Y M D H M S format." << endl;
    cin >> d.year >> d.month >> d.day >> d.hours >> d.minutes >> d.seconds;

    rem.seconds = 59 - d.seconds;
    rem.minutes = 59 - d.minutes;
    rem.hours = 23 - d.hours;
    if(isSkipYear(d.year)){
        rem.day = GAPYEAR[d.month] - d.day;
    } else {
        rem.day = NOTGAPYEAR[d.month] - d.day;
    }
    rem.month = 12 - d.month;


}
/*
void dayLeft(){
    int h, m, s;

    cout << "Enter the time int H M S format." << endl;
    cin >> h >> m >> s;

    int remaining = V - h*60*60 - m*60 - s;
    int rH = remaining / 60 / 60;
    remaining %= (60*60);
    int rM = remaining / 60;
    remaining %= 60;
    int rS = remaining;

    cout << "Remaining: " << rH << ", " << rM << ", " << rS << endl;
}
*/
int main() {
    int funcCode;
    bool shouldStop = false;
    while(!shouldStop) {
        cout << "Enter func code: Exit(0), SN1(1), SN2(2), Factorial(3), modulo(4)" << endl;
        funcCode = readNumber(true, "function number");
        switch(funcCode) {
        case 0:
            shouldStop = true;
            break;
        case 1:
            cout << siknegyed() << endl;
            break;
        case 2:
            cout << siknegyed2() << endl;
            break;
        case 3:
            cout << factorial() << endl;
            break;
        case 4:
            cout << mod() << endl;
            break;
        case 5:
            break;
        default:
            break;
        }
    }
}

