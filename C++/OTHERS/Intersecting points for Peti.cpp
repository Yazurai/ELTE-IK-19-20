#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

typedef struct _square{
    int x, y, r;
}square;

bool isIntersecting(square a, square b){
    return (abs(a.x-b.x) <= (a.r+b.r)) && (abs(a.y-b.y) <= (a.r+b.r));
}

int main(){
    int M, N;
    cin >> M >> N;
    square areas[M];
    for(int i = 0; i < M; i++){
        cin >> areas[i].x >> areas[i].y >> areas[i].r;
    }
    //Used vectors but you could use an array and a counter too
    vector <int> standaloneAreas;
    for(int i = 0; i < M; i++){
        bool isSeparate = true;
        int j = 0;
        for(int j = 0; j < M; j++){
            if(j != i && isIntersecting(areas[i], areas[j])){
                isSeparate = false;
            }
        }
        if(isSeparate){
            standaloneAreas.push_back(i+1);
        }
    }
    if(standaloneAreas.size() == 0){
        cout << 0;
    }
    for(int i = 0; i < standaloneAreas.size(); i++){
        cout << standaloneAreas[i] << " ";
    }
}
