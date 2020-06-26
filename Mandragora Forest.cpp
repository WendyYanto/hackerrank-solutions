#include <bits/stdc++.h>
using namespace std;

long long max(long long a, long long b){
    if (a>b){
        return a;
    }
    return b;
}

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        long long beasts[n+1];
        long long sum[n+1];
        for(int i=0;i<n;i++) {
            cin>>beasts[i];
        }
        sort(beasts, beasts +  n);
        long long output = INT_MIN;
        sum[n-1] = beasts[n-1];
        for(long long i=(n-2);i>=0;i--){
            sum[i] = sum[i+1] + beasts[i];
        }
        long long health = 1;
        for(long long i=0;i<n;i++){
            output = max(output, health*sum[i]);
            health += 1;
        }
        cout<<output<<endl;
    }
    return 0;
}