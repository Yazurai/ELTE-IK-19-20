#include <iostream>
#include <string>
#include <sstream>

using namespace std;

typedef struct _student{
    string name;
    int height;
}student;

int main(){
    int n;
    cin >> n;
    student sts[n];

    for(int i = 0; i < n; i++){
        cin >> sts[i].name >> sts[i].height;
    }

    bool isOrdered = true;
    for(int i = 0; i < n-1; i++){
        if(sts[i].height > sts[i+1].height ){
            isOrdered = false;
        }
    }

    cout << (isOrdered ? "IGEN" : "NEM");
}
