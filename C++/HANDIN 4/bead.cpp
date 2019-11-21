#include <iostream>

#define MAXN 1000

using namespace std;

int main(){
    int n = 0, m = 0;
    cin >> n >> m;
    int temps[MAXN][MAXN];
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> temps[i][j];
        }
    }

    int counter = 0;
    int goodDays[MAXN];
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
            goodDays[counter] = i+1;
            counter++;
        }
    }

    cout << counter;
    for(int i = 0; i < counter; i++){
        cout << " " << goodDays[i];
    }

    return 0;
}

/*

3 5
10 15 12 10 10
11 11 11 11 20
12 16 16 16 20


*/
