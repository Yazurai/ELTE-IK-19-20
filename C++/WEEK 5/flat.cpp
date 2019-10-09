#include <iostream>
#include <vector>

using namespace std;

typedef struct _flat{
    int area;
    int price;
}flat;

int main(){
    int n, price;
    cin >> n >> price;
    flat flats[n];

    for(int i = 0; i < n; i++){
        cin >> flats[i].area >> flats[i].price;
    }

    vector <int> indexes;
    for(int i = 0; i < n; i++){
        if(flats[i].price > price){
            indexes.push_back(i+1);
        }
    }

    cout << indexes.size();
    for(int i = 0; i < indexes.size(); i++){
        cout << " " << indexes[i];
    }

    return 0;
}
