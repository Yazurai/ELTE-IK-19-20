#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

int main(){
    //Getting input data
    int n;
    string name;
    cin >> n >> name;
    cin.ignore();

    //Filling up the data structure
    vector <string> names;
    for(int i = 0; i < n; i++){
        string newLine;
        getline(cin, newLine);
        names.push_back(newLine);
    }

    //Calculating the results
    int dayCount = 0;
    vector <int> days;
    for(int i = 0; i < n; i++){
        bool found = false;
        stringstream ss(names[i]);
        string s;
        while(getline(ss, s, ',')){
            if(s.compare(name) == 0){
                found = true;
            }
        }
        if(found){
            days.push_back(i+1);
            dayCount++;
        }
    }

    //Printing the results
    cout << dayCount;
    for(int i = 0; i < dayCount; i++){
        cout << " " << days[i];
    }
    return 0;
}
