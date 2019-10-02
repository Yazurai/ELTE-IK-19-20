#include <iostream>

using namespace std;

int main(){
    int N, K = 5;
    cin >> N;
    int fishCounts[N];
    for(int i = 0; i < N; i++){
        cin >> fishCounts[i];
    }

    int sum = 0;
    for(int i = 0; i < N; i++){
        sum += fishCounts[i] < K ? fishCounts[i] : 0;
    }

    cout << sum << endl;
}
