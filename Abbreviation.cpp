#include <bits/stdc++.h>
using namespace std;

// To Do

int main() {
    int t;
    cin>>t;
    map<int, int> characters;
    while(t--) {
        string from, to;
        cin>>from>>to;
        for(int i=0;i<from.length();i++) {
            from[i] = toupper(from[i]);
            characters[tolower(from[i]) - 'a']++;
        }
        int flag = false;
        for(int i=0;i<to.length();i++) {
            if(characters[tolower(to[i]) - 'a'] == 0) {
                flag = true;
                break;
            }
        }
        if (flag) {
            // Doesn't contain character to form TO;
            cout<<"NO"<<endl;
        } else {
            // Contain ALL 
            // Can be in different order
            if (from.length() >= to.length()) {
                // Traverse DP
            } else {
                // Not Equal length
                cout<<"NO"<<endl;
            }
        }
        characters.clear();
    }
    return 0;
}