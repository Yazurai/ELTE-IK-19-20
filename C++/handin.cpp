#include <iostream>
#include <cmath>

#define MAXN 10000

using namespace std;

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
            for(int j = 0; j < N; j++) {
                if(j != i) {
                    bool canSee = true;
                    double heightDiff = abs(heights[i] - heights[j]);
                    double diff = abs(i-j);
                    double avgDiff = heightDiff / diff;
                    if(j < i){
                        for(int k = j; k < i-1; k++){
                            if(heights[k] > heights[j] + abs(k-j) * avgDiff){
                                canSee = false;
                                break;
                            }
                        }
                    } else {
                        for(int k = i+1; k < j; k++){
                            if(heights[k] > heights[j] + abs(k-j) * avgDiff){
                                 canSee = false;
                                 break;
                            }
                        }
                    }
                    if(canSee){
                        counter++;
                    }
                }
            }
            if(counter > maximum){
                maximum = counter;
                index = i;
            }
        }
    }

    if(maximum == -1){
        cout << "0";
    } else {
        cout << index + 1;
    }
}


/*

12
9 2 1 9 0 3 2 0 0 1 2 9



*/
