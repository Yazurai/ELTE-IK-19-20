#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    bool days[n];

    for(int i = 0; i < n; i++) {
        cin >> days[i];
    }

    int i = 0, acc = 0;
    while(i <= n && acc < 7) {
        acc = days[i] ? acc + 1 : 0;
        i++;
    }

    int index = i - acc + 1;

    cout << index;
}
