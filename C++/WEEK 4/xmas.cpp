#include <iostream>

using namespace std;

int main() {
    int N, K;
    cin >> N;
    cin >> K;

    int prices[N];
    for(int i = 0; i < N; i++) {
        cin >> prices[i];
    }

    int treeIndex = -2;
    for(int i = 0; i < N; i++) {
        if(prices[i]<K) {
            treeIndex = i;
            break;
        }
    }

    cout << treeIndex + 1 << endl;
    return 0;
}
