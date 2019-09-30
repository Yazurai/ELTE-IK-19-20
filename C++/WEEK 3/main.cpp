#include <iostream>

using namespace std;

static const int cardCount = 8;
static char const* cards[cardCount] = {"VII", "VIII", "IX", "X", "ASZ", "KIRALY", "FELSO", "ALSO"};
static int const values[cardCount] = {7, 8, 9, 10, 11, 4, 3, 2};

int findValue(string k) {
    for(int i = 0; i < cardCount; i++) {
        if(cards[i] == k) {
            return values[i];
        }
    }
    return 0;
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
            cout << "Wrong input!" << endl;
        } else {
            int e = findValue(k);
            if(e == 0) {
                cout << "Wrong input!" << endl;
                inputIsCorrect = false;
            } else {
                cout << "The value of " << k << " is:" << e << endl;
            }
        }
    }
    return 0;
}
