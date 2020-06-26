#include <bits/stdc++.h>
using namespace std;

int main() {
    string word;
    cin>>word;
    int count = 0;
    for(int i=0;i<word.length();i+=3) {
        if (word[i] != 'S') {
            count++;
        }
        if (word[i+1] != 'O') {
            count++;
        }
        if (word[i+2] != 'S') {
            count++;
        }
    }
    cout<<count<<endl;
    return 0;
}