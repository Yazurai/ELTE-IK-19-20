#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;

    double H[n];
    for(int i = 0; i < n; i++) {
        cin >> H[i];
    }

    double maxTemp = 0;
    int maxIndex = 0;
    for(int i = 1; i < n-1; i++) {
        double wrongness = abs((H[i-1] + H[i+1]) / 2 - H[i]);
        if(wrongness > maxTemp) {
            maxTemp = wrongness;
            maxIndex = i+1;
        }
    }

    cout << maxIndex;
}
