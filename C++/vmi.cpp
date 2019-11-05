#include <iostream>

#define MAXN 100
#define MAXM 1000

using namespace std;

int main(){
    int N, M, K;
    cin >> N >> M >> K;
    bool termek[MAXN][MAXM];

    for(int i = 0; i < K; i++){
        int sorszam, start, finish;
        cin >> sorszam >> start >> finish;
        for(int j = start; j <= finish ; j++){
            termek[sorszam-1][j-1] = true;
        }
    }

    int maxIndex = -1, maxValue = 0, s = 0, f = 0;
    for(int i = 0; i < N; i++){
        int currS = 1, curr = 0, max1 = 0, start = 0, finish = 0;
        for(int j = 0; j < M ; j++){
            if(termek[i][j]){
                curr = 0;
                currS = j+2;
            } else {
                curr++;
                if(curr > max1){
                    start = currS;
                    finish = j+1;
                    max1 = curr;
                }
            }
        }

        if(max1 > maxValue){
            maxIndex = i;
            maxValue = max1;
            s = start;
            f = finish;
        }
    }

    if(maxIndex == -1){
        cout << "0" << endl;
        cout << "0 0";
    } else {
        cout << maxIndex+1 << endl;
        cout << s << " " << f;
    }
}

/*
3 10 5
1 4 8
2 3 5
3 8 8
2 6 9
3 1 4

*/

/*int main()
{ const int maxn= 1000;
    int n, k, fog;
    cerr<< "n=" << endl;
    cin>> n;
    cerr<< "k="<< endl;
    cin >> k;
    cerr << "fog="<< endl;
    cin >> fog;
    typedef struct{
    int teremszam;
    int kezdes;
    int vegzes;

    }termek;
    termek b[maxn];
    for (int i =1; i<=fog; i++){
        cin >>b[i-1].teremszam;
        cin >>b[i-1].kezdes;
        cin >>b[i-1].vegzes;
    }
    int foglalt[maxn];
for (int i=1; i<=fog; i++){
        for( int j=1; j<=fog; j++){
            if (==b[i].teremszam)
                foglalt[j]=
        }
}
}*/
