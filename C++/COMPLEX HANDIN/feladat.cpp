#include <iostream>
#include <vector>

#define MAXN 1000

using namespace std;

int main(){
    int n = 0, m = 0;
    int temps[MAXN][MAXN];

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            temps[i][j] = readNumber(-50, 50, "Enter a temperature:");
        }
    }

    vector <int> goodDays;
    for (int i = 0; i < n; i++){
        double avg = 0;
        int sum = 0, maxT = -51, minT = 51, temp = 0;
        for (int j = 0; j < m; j++){
            temp = temps[i][j];
            sum += temp;
            if(temp > maxT){
                maxT = temp;
            }
            if(temp < minT){
                minT = temp;
            }
        }
        avg = sum / (double)m;
        if(maxT-avg > avg-minT){
            goodDays.push_back(i+1);
        }
    }

    cout << counter;
    for(int i = 0; i < goodDays.size; i++){
        cout << " " << goodDays[i];
    }

    return 0;
}

/**
 * Calculates the sum of decimal values inside of an array.
 *
 * @param list the array that we take take the values from.
 * @param length The length of the array.
 * @return returns the sum.
 */
int max(int list[], int length){
    int sum = 0;
    for(int i = 1; i < length; i++){
        sum +=  list[i];
    }
    return sum;
}

/**
 * Calculates the average of decimal values inside of an array.
 *
 * @param list the array that we take take the values from.
 * @param length The length of the array.
 * @return returns the average.
 */
double avg(int list[], int length){
    return max(list, length) / (double)length;
}

/**
 * Takes the maximum value found in an n length array.
 *
 * @param list the array that we take take the values from.
 * @param length The length of the array.
 * @return returns the maximum.
 */
int max(int list[], int length){
    int maximum = list[0];
    for(int i = 1; i < length; i++){
        maximum = maximum < list[i] ? list[i] : maximum;
    }
    return maximum;
}

/**
 * Takes the minimum value found in an n length array.
 *
 * @param list the array that we take take the values from.
 * @param length The length of the array.
 * @return returns the minimum.
 */
int min(int list[], int length){
    int minimum = list[0];
    for(int i = 1; i < length; i++){
        minimum = list[i] < minimum ? list[i] : minimum;
    }
    return minimum;
}

/**
 * Reads in a single number from standard input.
 *
 * Continuously retries until a good input value is given.
 *
 * @param min The minimal accepted number (included).
 * @param max The maximal accepted number (included).
 * @return returns the read in number.
 */
int readNumber(int min, int max, string msg){
    int x;
    bool inputCorrect = false;
    while(!inputCorrect) {
        cout << msg;
        cin >> x;
        inputCorrect = x < min || max < x || cin.fail();
        if(!inputCorrect) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Wrong input!" << endl;
        }
    }
    return x;
}

/*

3 5
10 15 12 10 10
11 11 11 11 20
12 16 16 16 20


*/
