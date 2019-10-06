#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;

    float temps[n];
    for(int i = 0; i < n; i++) {
        cin >> temps[i];
    }

    float maxTemp = 0, maxIndex = 0;
    for(int i = 1; i < n-1; i++) {
        float tempAverage = (temps[i-1] + temps[i+1]) / 2;
        if(abs(tempAverage - temps[i]) > maxTemp) {
            maxTemp = abs(tempAverage - temps[i]);
            maxIndex = i + 1;
        }
    }

    cout << maxIndex;
}
