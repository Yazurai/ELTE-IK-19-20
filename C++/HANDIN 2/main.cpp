#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

int main() {
    //Getting input data
    int n;
    string name;
    cin >> n >> name;
    cin.ignore(); //ignore '\n' for getline

    //Filling up the data structure
    vector <string> days;
    for(int i = 0; i < n; i++) {
        string newLine;
        getline(cin, newLine);
        days.push_back(newLine);
    }

    //Calculating the results
    vector <int> foundDays;
    for(int i = 0; i < n; i++) {
        bool found = false;
        stringstream ns(days[i]);
        string n;
        while(getline(ns, n, ',')) {
            if(n.compare(name) == 0) {
                found = true;
            }
        }
        if(found) {
            foundDays.push_back(i+1);
        }
    }

    //Printing the results
    cout << foundDays.size();
    for(int i = 0; i < foundDays.size(); i++) {
        cout << " " << foundDays[i];
    }
}
