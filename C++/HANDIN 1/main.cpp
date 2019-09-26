#include <iostream>

using namespace std;

void processScore(int *scores, int size);
void printMaxes(int *array, int size);
int getMax(int scores[], int pCount);

int main() {
    //cout << "Enter playerCount and roundCount:";
    int playerCount, roundCount;
    cin >> playerCount >> roundCount;
    int scores[playerCount] = { };
    for(int i = 0; i < roundCount; i++) {
        processScore(scores, playerCount);
    }
}

void processScore(int scores[], int pCount) {
    //cout << "Enter round data:";
    int winner, loser;
    cin >> winner >> loser;
    scores[winner-1]++;
    scores[loser-1]--;
    printMaxes(scores, pCount);
}

void printMaxes(int scores[], int pCount) {
    int maximum = getMax(scores, pCount);
    for(int i = 0; i < pCount; i++) {
        if(scores[i] == maximum) {
            cout << i + 1 << " ";
        }
    }
    cout << endl;
}

int getMax(int scores[], int pCount) {
    int maximum = scores[0];
    for(int i = 1; i < pCount; i++) {
        if(scores[i] > maximum) {
            maximum = scores[i];
        }
    }
    return maximum;
}
