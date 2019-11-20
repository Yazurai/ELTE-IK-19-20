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

typedef struct hsData {
    int before;
    int after;
}hotspot;

static int N = 0, M = 0, K = 0;
static int temps[MAXD][MAXD];
static bool hotspots[MAXD][MAXD];
static divisor divs[MAXD];
static hsData hor[MAXD];
static hsData ver[MAXD];
int hsCount = 0;
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

    /*position pos(0,0);
    horizontal.push_back(pos);
    vertical.push_back(pos);*/
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
    hsCount = horizontal.size();
    for(int y = 0; y < N; y++) {
        int last = -1;
        for(int z = 0; z < hsCount && vertical[z].y <= y; z++) {
            last++;
        }
        ver[y].before = last;
    }
    for(int y = 0; y < N; y++) {
        int last = 0;
        for(int z = 0; z < hsCount && vertical[z].y < y; z++) {
            last++;
        }
        ver[y].after = last;
    }
    for(int x = 0; x < M; x++) {
        int last = -1;
        for(int z = 0; z < hsCount && horizontal[z].x <= x; z++) {
            last++;
        }
        hor[x].before = last;
    }
    for(int x = 0; x < M; x++) {
        int last = 0;
        for(int z = 0; z < hsCount && horizontal[z].x < x; z++) {
            last++;
        }
        hor[x].after = last;
    }

    printf("hsCount:%d \n",hsCount);
    for(int y = 0; y < N; y++) {
        for(int x = 0; x < M; x++) {
            cout << hotspots[y][x];
        }
        cout << endl;
    }
    cout << "horizontal toleft" << endl;
    for(int x = 0; x < M; x++) {
        cout << hor[x].before << " ";
    }
    cout << endl;
    cout << "horizontal toright" << endl;
    for(int x = 0; x < M; x++) {
        cout << hor[x].after << " ";
    }
    cout << endl;
    cout << "vertical above" << endl;
    for(int y = 0; y < N; y++) {
        cout << ver[y].before << " ";
    }
    cout << endl;
    cout << "vertical below" << endl;
    for(int y = 0; y < N; y++) {
        cout << ver[y].after << " ";
    }
    cout << endl;
    int divCount = getDivs(K);

    rectangle best;
    int maxHotspot = -1;
    for(int i = 0; i < divCount; i++) {
        if(divs[i].m <= M || divs[i].n <= N) {
            for(int y = 0; y <= N-divs[i].n; y++) {
                for(int x = 0; x <= M-divs[i].m; x++) {
                    rectangle curr;
                    curr.setRect(x, y, x+divs[i].m-1, y+divs[i].n-1);
                    int hotspotCount = checkArea(curr);
                    if(hotspotCount > maxHotspot) {
                        maxHotspot = hotspotCount;
                        best = curr;
                    }
                }
            }
        }
    }

    cout << best.a.y+1 << " " << best.a.x+1 << " " << best.b.y+1 << " " << best.b.x+1;

    return 0;
}

/*

5 6 1
2 1 3 1 1 1
1 1 2 1 1 1
3 2 1 1 2 1
1 1 2 1 1 1
1 1 1 1 1 1


5 6 9
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
