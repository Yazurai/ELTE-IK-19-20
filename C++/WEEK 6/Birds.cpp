#include <iostream>
#include <cstdlib>
#include <cstring>
#include <sstream>

#define MAX_M 50
#define MAX_N 200

using namespace std;

int main() {
    int rooms[MAX_M][MAX_N];
    int M, N;
    cin >> M >> N;
    cin.ignore();
    for(int m = 0; m < M; m++) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        for(int n = 0; n < N; n++) {
            string elem;
            getline(ss, elem, ' ');
            rooms[m][n] = atoi(elem.c_str());
        }
    }
    bool found = false;
    int m = 0;
    while(m < M && !found) {
        bool allZero = true;
        int n = 0;
        while(n < N && allZero) {
            if(rooms[m][n] != 0) {
                allZero = false;
            }
            n++;
        }
        if(allZero) {
            found = true;
        }
        m++;
    }
    int foundIndex = found ? m : 0;
    cout << foundIndex;
}
