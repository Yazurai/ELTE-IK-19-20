#include <iostream>
#include <cmath>

#define MAXD 1000

using namespace std;

typedef struct _divisor {
    int a, b;
} divisor;

typedef struct _rectangle {
    int x1, y1;
    int x2, y2;

    void rectangle() {
        x1 = 0;
        y1 = 0;
        x2 = 0;
        y2 = 0;
    }

    void rectangle(int x1, int y1, int x2, int y2) {
        x1 = x1;
        y1 = y1;
        x2 = x2;
        y2 = y2;
    }

    void setRect(int x1, int y1, int x2, int y2) {
        x1 = x1;
        y1 = y1;
        x2 = x2;
        y2 = y2;
    }
} rectangle;

static int N = 0, M = 0, K = 0;
static int temps[MAXD][MAXD];
static bool hotspots[MAXD][MAXD];
static divisor divs[MAXD];

bool isHotspot(int posX, int posY) {
    int counter = 0;
    for(int y = posY-1; y <= posY+1 && counter < 4; y++) {
        for(int x = posX-1; x <= posX+1 && counter < 4; x++) {
            if(0 <= y && y < N && 0 <= x && x < M) {
                if(posX != x && posY != y && temps[y][x] < temps[posY][posX]) {
                    counter++;
                }
            }
        }
    }
    return counter >= 4;
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
            for(int y = 0; y < N-divs[i].b; y++) {
                for(int x = 0; x < M-divs[i].a; x++) {
                    rectangle curr = setRect(x, y, x+divs[i].a, y+divs[i].b);
                    int hotspotCount = checkArea(curr);
                    if(hotspotCount > maxHotspot) {
                        maxHotspot = hotspotCount;
                        best = curr;
                    }
                }
            }
        }
    }

    cout << best.y1 << " " << best.x1 << " " << best.y2 << " " << best.x2;

    return 0;
}

/*

5 6 8
1 1 1 1 1 1
1 1 2 1 1 1
1 2 1 1 2 1
1 1 2 1 1 1
1 1 1 1 1 1


*/
