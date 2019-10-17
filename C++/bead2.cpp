#include <iostream>

using namespace std;

struct Ter{
    int x,y,r;
};

bool isNotOverlap(Ter a, Ter b){
    return
        a.y+a.r < b.y-b.r ||
        a.x+a.r < b.x-b.r ||
        b.y+b.r < a.y-a.r ||
        b.x+b.r < a.x-a.r;
}

int main()
{
    int n,k;
    cin >> n >> k;
    Ter ter[n];
    for(int i=0; i<n; ++i){
        cin >> ter[i].x >> ter[i].y >> ter[i].r;
    }


    int j;
    int db=0;
    int megold[n];
    bool isNotOverlapLocal;
    for(int i=0; i<n; ++i){
        j=0;
        isNotOverlapLocal = true;
        while(j<n && isNotOverlapLocal){
            if(j == i) j++;
            else{
                isNotOverlapLocal = isNotOverlap(ter[i],ter[j]);
                ++j;
            }
        }
        if(isNotOverlapLocal){
            megold[db] = i+1;
            db++;
        }
    }
    for(int i=0;i<db-1; ++i) cout << megold[i] << " "; cout << megold[db-1];
    return 0;
}
