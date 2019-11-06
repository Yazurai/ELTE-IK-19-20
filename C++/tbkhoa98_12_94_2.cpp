#include <iostream>
#include <cmath>

#define MAXD 1000

using namespace std;

typedef struct _divisor {
    int a, b;
} divisor;

typedef struct rectangle {
    int x1, y1;
    int x2, y2;

    rectangle() {
        x1 = 0;
        y1 = 0;
        x2 = 0;
        y2 = 0;
    }

    rectangle(int x1, int y1, int x2, int y2) {
        x1 = x1;
        y1 = y1;
        x2 = x2;
        y2 = y2;
    }

    void setRect(int newX1, int newY1, int newX2, int newY2) {
        x1 = newX1;
        y1 = newY1;
        x2 = newX2;
        y2 = newY2;
    }
} rectangle;

static int N = 0, M = 0, K = 0;
static int temps[MAXD][MAXD];
static bool hotspots[MAXD][MAXD];
static divisor divs[MAXD];

bool checkPos(int x1, int y1, int x2, int y2){
    if(0 <= y1 && y1 < N && 0 <= x1 && x1 < M) {
        if(temps[y1][x1] < temps[y2][x2]) {
            return true;
        } else {
            return false;
        }
    }
    return false;
}

bool isHotspot(int x, int y) {
    if(!checkPos(x-1,y,x,y)){
        return false;
    }
    if(!checkPos(x+1,y,x,y)){
        return false;
    }
    if(!checkPos(x,y-1,x,y)){
        return false;
    }
    if(!checkPos(x,y+1,x,y)){
        return false;
    }
    return true;
}

int checkArea(rectangle rect) {
    int counter = 0;
    for(int y = rect.y1; y <= rect.y2; y++) {
        for(int x = rect.x1; x <= rect.x2; x++) {
            if(hotspots[y][x]) {
                counter++;
            }
        }
    }
    return counter;
}

int getDivs(int n) {
    int counter = 0;
    for(int i = 1; i <= n; i++) {
        if(n % i == 0) {
            divs[counter].a = i;
            divs[counter].b = n/i;
            counter++;
        }
    }
    return counter;
}

int main() {
    cin >> N >> M >> K;
    for(int y = 0; y < N; y++) {
        for(int x = 0; x < M; x++) {
            cin >> temps[y][x];
        }
    }

    for(int y = 0; y < N; y++) {
        for(int x = 0; x < M; x++) {
            hotspots[y][x] = isHotspot(x,y);
        }
    }

    int divCount = getDivs(K);

    rectangle best;
    int maxHotspot = 0;
    for(int i = 0; i < divCount; i++) {
        if(divs[i].a <= M || divs[i].b <= N) {
            for(int y = 0; y <= N-divs[i].b; y++) {
                for(int x = 0; x <= M-divs[i].a; x++) {
                    rectangle curr;
                    curr.setRect(x, y, x+divs[i].a-1, y+divs[i].b-1);
                    int hotspotCount = checkArea(curr);
                    if(hotspotCount > maxHotspot) {
                        maxHotspot = hotspotCount;
                        best = curr;
                    }
                }
            }
        }
    }

    cout << best.y1+1 << " " << best.x1+1 << " " << best.y2+1 << " " << best.x2+1;

    return 0;
}

/*

5 6 8
1 1 1 1 1 1
1 1 2 1 1 1
1 2 1 1 2 1
1 1 2 1 1 1
1 1 1 1 1 1

5 6 8
2 1 1 1 1 1
1 1 1 1 1 1
1 1 1 1 1 1
1 1 1 1 1 1
1 1 1 1 1 1

*/
