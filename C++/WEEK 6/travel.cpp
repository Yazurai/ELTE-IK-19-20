#include <iostream>
#include <cmath>

using namespace std;

typedef struct _ticket{
    int distance;
    int cost;
}ticket;

int main(){
    int n;
    cin >> n;
    ticket tickets[n];
    for(int i = 0; i < n; i++){
        cin >> tickets[i].distance >> tickets[i].cost;
    }
    int maxCost = -INFINITY;
    for(int i = 0; i < n; i++){
        if(tickets[i].distance < 1000 && tickets[i].cost > maxCost){
            maxCost = tickets[i].cost;
        }
    }
    maxCost = maxCost < 0 ? -1 : maxCost;
    cout << maxCost;
}
