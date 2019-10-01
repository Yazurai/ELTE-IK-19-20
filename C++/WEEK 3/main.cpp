#include <iostream>

using namespace std;

//Could have used a maptable or struct
static const int cardCount = 8;
static char const* cards[cardCount] = {"VII", "VIII", "IX", "X", "ASZ", "KIRALY", "FELSO", "ALSO"};
static int const values[cardCount] = {7, 8, 9, 10, 11, 4, 3, 2};

//Finds a card
int findCard(string k) {
    for(int i = 0; i < cardCount; i++) {
        if(cards[i] == k) {
            return values[i];
        }
    }
    return 0;
}

//This one follows the algorithm strictly
int findCard2(string k) {
    int value = 0;
    for(int i = 0; i < cardCount; i++) {
        if(cards[i] == k) {
            value = values[i];
        }
    }
    return value;
}

int main() {
    string k;
    bool inputIsCorrect = false;
    while(!inputIsCorrect) {
        cout << "Please enter the name of the card (VII, VIII, IX, X, ASZ, KIRALY, FELSO, ALSO)" << endl;
        cin >> k;
        cin.ignore(1000, '\n');
        inputIsCorrect = !cin.fail();
        if(!inputIsCorrect) {
            cin.clear();
            cin.ignore(1000, '\n');
            cerr << "Wrong input!" << endl;
        } else {
            int e = findCard(k);
            if(e == 0) {
                cerr << "Wrong input!" << endl;
                inputIsCorrect = false;
            } else {
                cout << "The value of " << k << " is:" << e << endl;
            }
        }
    }
    return 0;
}
