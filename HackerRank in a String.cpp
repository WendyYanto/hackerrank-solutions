#include <bits/stdc++.h>
using namespace std;

bool isContain(string word) {
    char comparator[] = {'h', 'a', 'c', 'k', 'e', 'r', 'r', 'a', 'n', 'k'};
    int n = 10;
    int c_index = 0;
    int index = 0;
    while(index < word.length() && c_index < n) {
        if (word[index] == comparator[c_index]) {
            index++;
            c_index++;
        } else {
            index++;
        }
    }
    return c_index == n;
}

int main() {
    int n;
    cin>>n;
    while(n--){
        string word;
        cin>>word;
        if(isContain(word)) {
            cout<<"YES"<<endl;
        } else {
            cout<<"NO"<<endl;
        }
    }
    return 0;
}