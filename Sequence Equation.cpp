#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    map<int, int> equation;
    vector<int> x;
    for(int i=0;i<n;i++) {
        int input;
        cin>>input;
        x.push_back(input);
        equation[input] = i+1;
    }
    for(int i=0;i<x.size();i++){
        cout<<equation[equation[equation[x[i]]]]<<endl;
    }
    return 0;
}