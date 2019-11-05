#include <iostream>
#include <cmath>

#define MAXN 10000

using namespace std;

int heights[MAXN];

bool raycast(int i, int j) {
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
    return canSee;
}

int main() {
    ios_base::sync_with_stdio(false);
    int N = 0;
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> heights[i];
    }

    int maximum = -1, index = 0;
    for(int i = 0; i < N; i++) {
        if(heights[i] != 0) {
            int counter = 0;
            int currHighest = 0;
            for(int j = i-1; j >= 0; j--) {
                if(currHighest < heights[i] || (currHighest >= heights[i] && heights[j] > currHighest)) {
                    bool canSee = raycast(i, j);
                    currHighest = heights[j];
                    if(canSee) {
                        counter++;
                    }
                }
            }

            currHighest = 0;
            for(int j = i+1; j < N; j++) {
                if(currHighest < heights[i] || (currHighest >= heights[i] && heights[j] > currHighest)) {
                    bool canSee = raycast(i, j);
                    currHighest = heights[j];
                    if(canSee) {
                        counter++;
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
9 2 1 9 0 3 2 0 0 3 2 9

12
0 0 0 0 0 0 0 0 0 0 0 0

5
0 0 0 1 2

*/
