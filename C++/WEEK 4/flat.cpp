#include <iostream>

using namespace std;

typedef struct _flat {
    int area;
    int price;
} flat;

int main() {
    int N;
    cin >> N;
    flat flats[N];
    for(int i = 0; i < N; i++) {
        cin >> flats[i].area >> flats[i].price;
    }

    int max = 0, maxIndex = 0;
    for(int i = 0; i < N; i++) {
        if(flats[i].price > max) {
            max = flats[i].price;
            maxIndex = i;
        }
    }
    cout << maxIndex + 1 << endl;
    return 0;
}
