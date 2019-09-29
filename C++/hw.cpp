#include <iostream>
#include <cmath>

using namespace std;

void ignoreLines(int lineCount) {
    for(int i = 0 i < lineCount; i++) {
        string line;
        cin.ignore();
        getline(cin,line);
    }
}

int main() {
    int eventCount, typeCount;
    cin >> eventCount;
    cin >> typeCount;
    int dates[eventCount];
    for(int i = 0; i < eventCount; i++) {
        cin >> dates[i];
        ignoreLine(2);
    }
    int minDate = 0;
    int minimum = dates[1] - dates[0];
    for(int i = 2; i < eventCount; i++) {
        int diff = abs(dates[i] - dates[i-1]);
        if(diff < minimum) {
            minimum = diff;
            minDate = i-1;
        }
    }
    ignoreLine(2 + typeCount);
    if(dates[minDate] < dates[minDate + 1]) {
        cout << minimum << " " << dates[minDate] << " " << dates[minDate + 1];
    } else {
        cout << minimum << " " << dates[minDate + 1] << " " << dates[minDate];
    }
    return 0;
}
