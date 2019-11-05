#include <iostream>

using namespace std;

typedef enum _eventType{LOGIN = 1, LOGOUT = -1, PAYIN = 2, TAKEOUT = -2}eventType;

typedef struct _time24{
    int hour;
    int minute;
}time24;

typedef struct _event{
    time24 t;
    int type;
    int value;
}event;

int main(){
    int N;
    cin >> N;

    event events[N];
    for(int i = 0; i < N; i++){
        cin >> events[i].t.hour >> events[i].t.minute >> events[i].type >> events[i].value;
    }

    int maxCount = 0, currCount = 0;
    bool currIsMax = true;
    time24 start;
    start.hour = 0;
    start.minute = 0;
    time24 finish;
    for(int i = 0; i < N; i++){
        if(events[i].type == LOGIN){
            currCount++;
            if(currCount > maxCount){
                maxCount = currCount;
                start = events[i].t;
                currIsMax = true;
            }
        }
        if(events[i].type == LOGOUT){
            if(currIsMax){
                finish = events[i].t;
                currIsMax = false;
            }
            currCount--;
        }
    }
    if(currIsMax){
        finish.hour = 23;
        finish.minute = 59;
    }

    cout << start.hour << " " << start.minute << " " << finish.hour << " " << finish.minute;

    return 0;
}
