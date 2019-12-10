/*
  Created by: Tran Bach Khoa
  Neptun: SAOF2T
  E-mail: tbkhoa98@gmail.com
  Exercise: Időjárás előrejelzés - Az átlag kisebb a minimum és maximum átlagánál
*/
#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;

const int MAXN = 1000;
const int MAXM = 1000;
const int MINT = -50;
const int MAXT = 50;
//Input:
int n = 0;
int m = 0;
int temps[MAXN][MAXM] = {0};
//Output:
vector <int> goodDays;

void readIn(int &n, int &m, int (&temps)[MAXN][MAXM]);
int readNumber(int min, int max);
void process(int &n, int &m, int (&temps)[MAXN][MAXM], vector<int> &goodDays);
double sumArray(const int list[], int n);
double avgArray(const int list[], int n);
int maxArray(const int list[], int n);
int minArray(const int list[], int n);
void printDays(const vector<int> &days);

int main(){
    readIn(n, m, temps);
    process(n, m, temps, goodDays);
    printDays(goodDays);
    return 0;
}

void readIn(int &n, int &m, int (&temps)[MAXN][MAXM]){
    cout << "Enter the number of cities[1.." << MAXN << "]:";
    n = readNumber(1, MAXN);
    cout << "Enter the number of days[1.." << MAXN << "]:";
    m = readNumber(1, MAXM);

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cout << "Enter the #" << j + 1 << " temperature for city #" << i + 1 << " [" << MINT << ".." << MAXT << "]:";
            temps[i][j] = readNumber(MINT, MAXT);
        }
        cin.ignore(1000, '\n');
    }
}

// Continuously tries to read in a single number from standard input.
// @min The minimal accepted number (included).
// @max The maximal accepted number (included).
int readNumber(int minVal, int maxVal){
    int x;
    bool inputCorrect = false;
    while(!inputCorrect) {
        cin >> x;
        inputCorrect = !(x < minVal || maxVal < x || cin.fail());
        if(!inputCorrect) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Wrong input, try again:";
        }
    }
    return x;
}

void process(int &n, int &m, int (&temps)[MAXN][MAXM], vector <int> &goodDays){
    for (int i = 0; i < n; i++){
        double avgT = avgArray(temps[i], m);
        int maxT = maxArray(temps[i], m);
        int minT = minArray(temps[i], m);
        if(maxT-avgT > avgT-minT){
            goodDays.push_back(i+1);
        }
    }
}

//Calculates the sum of decimal values inside of an array of n length.
double sumArray(const int* list, int n){
    double sum = 0;
    for(int i = 0; i < n; i++){
        sum += (double)list[i];
    }
    return sum;
}

//Calculates the average of decimal values inside of an array of n length.
double avgArray(const int* list, int n){
    double avg = sumArray(list, n) / (double)n;
    return avg;
}

//Takes the maximum value found in an n length array.
int maxArray(const int* list, int n){
    int maximum = list[0];
    for(int i = 1; i < n; i++){
        maximum = maximum < list[i] ? list[i] : maximum;
    }
    return maximum;
}

//Takes the minimum value found in an n length array.
int minArray(const int* list, int n){
    int minimum = list[0];
    for(int i = 1; i < n; i++){
        minimum = list[i] < minimum ? list[i] : minimum;
    }
    return minimum;
}

void printDays(const vector<int> &days){
    cout << "Number of cities that satisfy the given predicate: " << days.size() << endl;
    cout << "These cities are:";
    for(int i = 0; i < days.size(); i++){
        cout << " " << days[i];
    }
}