#include <iostream>

#define CARD_COUNT 32

using namespace std;

typedef struct _card{
    char color;
    char value;
} card;

int main(){
    card cards[CARD_COUNT];

    for(int i = 0; i < CARD_COUNT; i++){
        cin >> cards[i].color >> cards[i].value;
    }

    int i = 0;
    while(i < CARD_COUNT-1 && cards[i].value != cards[i+1].value){
        i++;
    }
    int index = i < CARD_COUNT-1 ? i+1 : 0;

    cout << index);
    return 0;
}
