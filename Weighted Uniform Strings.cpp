#include <bits/stdc++.h>
using namespace std;

map<int, int> combination;

void generateCombination(string word) {
    int sum = (word[0]-'a') + 1;
    combination[sum]++;
    for(int i=1;i<word.length();i++) {
        if (word[i] == word[i-1]) {
            sum += (word[i]-'a') + 1;
        } else {
            sum = (word[i]-'a') + 1;
        }
        combination[sum]++;
    }
}

int main() {
    string word;
    cin>>word;
    int t;
    cin>>t;
    generateCombination(word);
    while(t--) {
        int n;
        cin>>n;
        if (combination[n] != 0) {
            cout<<"Yes"<<endl;
        } else {
            cout<<"No"<<endl;
        }
    }
    return 0;
}