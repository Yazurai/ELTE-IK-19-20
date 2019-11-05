#include <iostream>
#include <math.h>

#define MAXN 100000

using namespace std;

int main(){
    int N = 0, K = 0, H = 0;
    cin >> N >> K >> H;

    int days[MAXN];
    for(int i = 0; i < N; i++){
        cin >> days[i];
    }

    bool found = false, isStreak = false;
    double minimum = INFINITY;
    int prev = -1, currStreak = 0;
    for(int i = 0; i < N; i++){
        if(isStreak){
            if(days[i] > H){
                currStreak++;
            }
            if(days[i] <= H){
                isStreak = false;
                if(currStreak >= K){
                    found = true;
                    if(prev != -1 && i - prev - 1 < minimum){
                        minimum = i - prev - 1;
                    }
                    prev = i;
                }
            }
        } else {
            if(days[i] > H){
                currStreak = 1;
                isStreak = true;
            }
        }
    }

    if(!found){
        cout << "-1" << endl;
    } else if(isinf(minimum)){
        cout << "-2" << endl;
    } else {
        cout << minimum << endl;;
    }
    return 0;
}

/*
13 2 25
20
26
24
26
27
28
20
20
28
28
25
28
29




13 2 25
26
26
25
25
25
25
25
26
26
26
26
26
25
*/
