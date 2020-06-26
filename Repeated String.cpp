#include <bits/stdc++.h>
using namespace std;

long repeatedString(string s, long n) {
    long output = 0;
    for(int i=0;i<s.length();i++){
        if(s[i] == 'a') {
            output++;
        }
    }
    long occurence = n/s.length();
    output *= occurence;
    long remaining = n - (occurence*s.length());
    for(int i=0;i<remaining;i++) {
        if(s[i] == 'a') {
            output++;
        }
    }
    return output;
}


int main() {
    string word;
    long n;
    cin>>word>>n;
    cout<<repeatedString(word, n)<<endl;
    return 0;
}