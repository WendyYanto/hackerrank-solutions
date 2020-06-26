#include <bits/stdc++.h>

using namespace std;

string caesarCipher(string s, int k) {
    string result = "";
    k %= 26;
    for(int i=0;i<s.length();i++) {
        int index = s[i] - 0;
        char x;
        if (index >= 65 && index <= 90) {
            // Capital Letter;
            if (index + k > 90) {
                x = (index + k) - 26;
            } else {
                x = index + k;
            }
            result.push_back(x);
        } else if (index >= 97 && index <= 122) {
            // Small Letter
            if (index + k > 122) {
                x = (index + k) - 26;
            } else {
                x = index + k;
            }
            result.push_back(x);
        } else {
            result.push_back(s[i]);
        }
    }
    return result;
}

int main() {
    int n;
    string word;
    int rotation;
    cin>>n>>word>>rotation;
    cout<<caesarCipher(word, rotation)<<endl;
    return 0;
}