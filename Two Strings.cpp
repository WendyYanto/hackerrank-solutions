#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    map<char, int> words;
    cin>>n;
    while(n--) {
        string s1, s2;
        cin>>s1>>s2;
        for(int i=0;i<s1.size();i++){
            words[s1[i]] = 1;
        }
        bool flag = false;
        for(int i=0;i<s2.size();i++){
            if(words[s2[i]] == 1) {
                flag = true;
                break;
            }
        }
        if (flag) {
            cout<<"YES"<<endl;
        } else {
            cout<<"NO"<<endl;
        }
        words.clear();
    }
    return 0;
}