#include <iostream>

#define MAXN 100
#define MAXDAYS 100000

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    int N;
    int travelTimes[MAXN];
    bool starts[MAXDAYS];

    cin >> N;
    for (int i = 1; i < N; i++){
        cin >> travelTimes[i];
    }

    int acc = 0;
    for (int i = 1; i < N; i++){
        acc += travelTimes[i] + 1;
        int n = 0;
        cin >> n;
        for (int j = 0; j < n; j++){
            int m;
            cin >> m;
            if(m - acc >= 0){
                starts[m - acc] = true;
            }
        }
    }

    int start = 0;
    while(starts[start] && start < MAXDAYS){
        start++;
    }

    cout << start+1;
}

/*

5
3 2 4 5
2 3 5
2 4 9
2 12 13
0


*/

