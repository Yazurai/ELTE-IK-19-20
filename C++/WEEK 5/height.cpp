#include <iostream>
#include <string>
#include <sstream>

using namespace std;

typedef struct _hooman{
    string name;
    int height;
}hooman;

int main(){
    int n;
    cin >> n;
    hooman hoomans[n];

    for(int i = 0; i < n; i++){
        cin >> hoomans[i].name >> hoomans[i].height;
    }

    bool isOrdered = true;
    for(int i = 0; i < n-1; i++){
        if(hoomans[i].height > hoomans[i+1].height ){
            isOrdered = false;
        }
    }

    cout << (isOrdered ? "IGEN" : "NEM");
}
