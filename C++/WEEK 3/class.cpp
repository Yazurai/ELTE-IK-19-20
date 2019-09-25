#include <iostream>
#include <math.h>

#define MAXN 100
#define MAXMM 1000
#define CURRYEAR 2019

using namespace std;

int readNumb(int limit);
void pedoAlert();
void rainy();
void pedoAlertFormal();

int main() {

}

void pedoAlert(){
    cout << "Enter the number of people:";
    int n = readNumb(MAXN);
    int mm[n];
    for(int i = 0; i < n; i++) {
        cout << "Enter the birth year of person " << i+1 << ":";
        mm[i] = readNumb(CURRYEAR);
    }

    bool pedoDanger = false;
    int i = 0;
    while(!pedoDanger){
        pedoDanger = CURRYEAR - mm[i] < 18;
        i++;
    }

    if(pedoDanger){
        cout << "PEDODANGER!" << endl;
    } else {
        cout << "All good." << endl;
    }
}

void pedoAlertFormal(){
    cout << "Enter the number of contestants:";
    int n = readNumb(MAXN);
    int mm[MAXN];
    for(int i = 0; i < n; i++) {
        cout << "Enter the birth year of person " << i+1 << ":";
        mm[i] = readNumb(CURRYEAR);
    }

    int i = 0;
    while(i<n && CURRYEAR - mm[i] >= 18){
        i++;
    }
    bool pedoDanger = i < n;
    if(pedoDanger){
        cout << "PEDODANGER!" << endl;
    } else {
        cout << "All good." << endl;
    }
}

void rainy() {
    cout << "Enter the number of days:";
    int n = readNumb(MAXN);;
    int mm[n];
    for(int i = 0; i < n; i++) {
        cout << "Enter day " << i+1 << " data:";
        mm[i] = readNumb(1000);
    }

    int cnt = 0;
    for(int i = 0; i < n; i++) {
        if(mm[i] != 0) {
            cnt++;
        }
    }

    cout << cnt << endl;
}


int readNumb(int limit) {
    int x;
    bool userIsIdiot = true;
    while(userIsIdiot) {
        cin >> x;
        userIsIdiot = (x < 0) || (x > limit) || (cin.fail());
        if(userIsIdiot) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Wrong input!" << endl;
        }
    }
    return x;
}
