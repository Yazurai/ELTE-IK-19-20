#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <cmath>

#define MAXD 1000

using namespace std;

typedef struct position {
    int x, y;

    position() {
        x = 0;
        y = 0;
    }

    position(int posX, int posY) {
        x = posX;
        y = posY;
    }
} position;

bool comparePosY(position a, position b) {
    return a.y < b.y;
}

bool comparePosX(position a, position b) {
    return a.x < b.x;
}

typedef struct _divisor {
    int m, n;
} divisor;

typedef struct rectangle {
    position a, b;

    rectangle() {
        a.x = 0;
        a.y = 0;
        b.x = 0;
        b.y = 0;
    }

    rectangle(position pos1, position pos2) {
        a.x = pos1.x;
        a.y = pos1.y;
        b.x = pos2.x;
        b.y = pos2.y;
    }

    rectangle(position pos, int height, int width) {
        a.x = pos.x;
        a.y = pos.y;
        b.x = pos.x+width;
        b.y = pos.y+height;
    }

    rectangle(int top, int bottom, int left, int right) {
        a.x = left;
        a.y = top;
        b.x = right;
        b.y = bottom;
    }

    void setRect(int x1, int y1, int x2, int y2) {
        a.x = x1;
        a.y = y1;
        b.x = x2;
        b.y = y2;
    }
} rectangle;

static int N = 0, M = 0, K = 0;
static int temps[MAXD][MAXD];
static bool hotspots[MAXD][MAXD];
static divisor divs[MAXD];
vector <position> horizontal;
vector <position> vertical;

void isHotspot(int x1, int y1, int x2, int y2) {
    if(temps[y1][x1] < temps[y2][x2]) {
        hotspots[y1][x1] = true;
    } else if (temps[y1][x1] > temps[y2][x2]) {
        hotspots[y2][x2] = true;
    } else {
        hotspots[y1][x1] = true;
        hotspots[y2][x2] = true;
    }
}

int checkArea(rectangle rect) {
    int counter = 0;
    for(int y = rect.a.y; y <= rect.b.y; y++) {
        for(int x = rect.a.x; x <= rect.b.x; x++) {
            if(!hotspots[y][x]) {
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
            divs[counter].m = i;
            divs[counter].n = n/i;
            counter++;
        }
    }
    return counter;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> N >> M >> K;
    for(int y = 0; y < N; y++) {
        for(int x = 0; x < M; x++) {
            cin >> temps[y][x];
        }
    }

    for(int y = 0; y < N; y++) {
        for(int x = 0; x < M-1; x++) {
            isHotspot(x,y,x+1,y);
        }
    }
    for(int y = 0; y < N-1; y++) {
        for(int x = 0; x < M; x++) {
            isHotspot(x,y,x,y+1);
        }
    }

    position pos(0,0);
    horizontal.push_back(pos);
    vertical.push_back(pos);
    for(int y = 0; y < N; y++) {
        for(int x = 0; x < M; x++) {
            if(!hotspots[y][x]) {
                position pos(x,y);
                horizontal.push_back(pos);
                vertical.push_back(pos);
            }
        }
    }

    sort(horizontal.begin(), horizontal.end(), comparePosX);

    int divCount = getDivs(K);

    rectangle best;
    int maxHotspot = -1;
    for(int k = 0; k < divCount; k++) {
        if(divs[k].m <= M || divs[k].n <= N) {
            for(int i = 0; i != horizontal.size(); i++) {
                int left = horizontal[i].x;
                int right = left+divs[k].m-1;
                if(right<M) {
                    for(int j = 0; j != vertical.size(); j++) {
                        if(vertical[j].x >= left && vertical[j].x <= right) {
                            int top = vertical[j].y;
                            int bottom = top+divs[k].n-1;
                            if(bottom<N) {
                                rectangle curr(top, bottom, left, right);
                                int hotspotCount = checkArea(curr);
                                if(hotspotCount > maxHotspot) {
                                    maxHotspot = hotspotCount;
                                    best = curr;
                                }
                            } else {
                                break;
                            }
                        }
                    }
                } else {
                    break;
                }
            }
        }
    }

    cout << best.a.y+1 << " " << best.a.x+1 << " " << best.b.y+1 << " " << best.b.x+1;

    return 0;
}

/*

5 6 8
2 1 3 1 1 1
1 1 2 1 1 1
3 2 1 1 2 1
1 1 2 1 1 1
1 1 1 1 1 1


5 6 5
1 1 1 1 1 1
1 1 2 1 1 1
1 2 1 2 1 2
1 1 1 1 2 1
1 1 1 2 1 2


5 6 8
1 1 1 1 1 1
1 1 1 1 1 1
1 1 1 1 1 1
1 1 1 1 1 1
1 1 1 1 1 1

*/
