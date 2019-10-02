#include <iostream>

using namespace std;

int main(){
    int towerCount = 0;
    cin >> towerCount;
    bool towers[towerCount];
    for(int i = 0; i < towerCount; i++){
        cin >> towers[i];
    }
    int protWallCount = 0;
    for(int i = 0; i < towerCount - 1; i++){
        if(towers[i] || towers[i+1]){
            protWallCount++;
        }
    }
    cout << protWallCount << endl;
    return 0;
}


