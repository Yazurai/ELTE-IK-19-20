#include <iostream>

using namespace std;

typedef enum _eventType{LOGIN = 1, LOGOUT = -1, PAYIN = 2, TAKEOUT = -2}eventType;

typedef struct _time{
    int hour;
    int minute;
}time;

typedef struct _event{
    time t;
    eventType type;
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
    bool currIsMax = false;
    time start;
    time finish;
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
                currCount--;
                finish = events[i].t;
                currIsMax = false;
            }
        }
    }
    if(currIsMax){
        finish = {23, 59};
    }

    cout << start.hour << start.minute << finish.hour << finish.minute;

    return 0;
}
