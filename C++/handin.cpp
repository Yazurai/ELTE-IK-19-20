#include <iostream>
#include <cmath>

#define MAXN 10000

using namespace std;

static bool seeData[MAXN][MAXN] = {0};

int main() {
    ios_base::sync_with_stdio(false);
    int N = 0;
    int heights[MAXN];
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> heights[i];
    }

    int maximum = -1, index = 0;
    for(int i = 0; i < N; i++) {
        if(heights[i] != 0) {
            int counter = 0;
            int currHighest = 0;
            for(int j = 0; j < i; j++) {
                if(seeData[j][i]){
                    counter++;
                }
            }
            currHighest = 0;
            for(int j = i+1; j < N; j++) {
                if(currHighest <= heights[i]) {
                    bool canSee = true;
                    double avgDiff = abs(heights[i] - heights[j]) / abs(i-j);
                    if(j < i) {
                        for(int k = j; k < i-1; k++) {
                            if(heights[k] > heights[j] + abs(k-j) * avgDiff) {
                                canSee = false;
                                break;
                            }
                        }
                    } else {
                        for(int k = i+1; k < j; k++) {
                            if(heights[k] > heights[j] + abs(k-j) * avgDiff) {
                                canSee = false;
                                break;
                            }
                        }
                    }
                    currHighest = heights[j];
                    if(canSee){
                        seeData[i][j] = true;
                        counter++;
                    }
                } else {
                    if(heights[j] > currHighest) {
                        bool canSee = true;
                        double avgDiff = abs(heights[i] - heights[j]) / abs(i-j);
                        if(j < i) {
                            for(int k = j; k < i-1; k++) {
                                if(heights[k] > heights[j] + abs(k-j) * avgDiff) {
                                    canSee = false;
                                    break;
                                }
                            }
                        } else {
                            for(int k = i+1; k < j; k++) {
                                if(heights[k] > heights[j] + abs(k-j) * avgDiff) {
                                    canSee = false;
                                    break;
                                }
                            }
                        }
                        currHighest = heights[j];
                        if(canSee){
                            seeData[i][j] = true;
                            counter++;
                        }
                    }
                }
            }
            if(counter > maximum) {
                maximum = counter;
                index = i;
            }
        }
    }

    if(maximum == -1) {
        cout << "0";
    } else {
        cout << index + 1;
    }
}


/*

12
9 2 1 9 0 3 2 0 0 1 2 9



*/
