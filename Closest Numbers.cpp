#include <bits/stdc++.h>
using namespace std;

long long min(long long a, long long b) {
    if (a < b) {
        return a;
    }
    return b;
}

int main() {
    long long n;
    cin>>n;
    long long number[n+1];
    for(int i=0;i<n;i++) {
        cin>>number[i];
    }
    sort(number, number + n);
    // find minimum
    long long diff = INT_MAX;
    for(int i=1;i<n;i++) {
        diff = min(diff, number[i] - number[i-1]);
    }
    for(int i=1;i<n;i++) {
        if(number[i] - number[i-1] == diff) {
            cout<<number[i-1]<<" "<<number[i]<<" ";
        }
    }
    return 0;
}