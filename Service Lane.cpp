#include <bits/stdc++.h>
using namespace std;

int min(int a, int b) {
    if (a<b){
        return a;
    }
    return b;
}

int main() {
    int n,t;
    cin>>n>>t;
    int spaces[n+1];
    for(int i=0;i<n;i++) {
        cin>>spaces[i];
    }
    int from, to, result;
    while(t--) {
        result = INT_MAX;
        cin>>from>>to;
        for(int i = from; i<=to; i++) {
            result = min(result, spaces[i]);
        }
        cout<<result<<endl;
    }
    return 0;
}