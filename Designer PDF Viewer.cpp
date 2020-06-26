#include <bits/stdc++.h>
using namespace std;

int max(int a, int b) {
    if(a>b){
        return a;
    }
    return b;
}

int main() {
    int heights[27];
    for(int i=0;i<26;i++) {
        cin>>heights[i];
    }
    string word;
    cin>>word;
    int tallest = INT_MIN;
    for(int i=0;i<word.size();i++) {
        tallest = max(tallest, heights[word[i] - 'a']);
    }
    cout<<tallest*word.size()<<endl;
    return 0;
}