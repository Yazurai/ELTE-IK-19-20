#include <iostream>
#include <cmath>

using namespace std;

typedef struct _yield{
    int amount;
    int price;
}yield;

int main(){
    int n;
    cin >> n;
    yield years[n];
    for(int i = 0; i < n; i++){
        cin >> years[i].amount >> years[i].price;
    }
    int currentMax = years[0].amount, recordCount = 0;
    int records[n];
    for(int i = 1; i < n; i++){
        if(years[i].amount > currentMax){
            currentMax = years[i].amount;
            records[recordCount] = i + 1;
            recordCount++;
        }
    }

    cout << recordCount << " ";
    for(int i = 0; i < recordCount; i++){
        cout << records[i] << " ";
    }
}
