#include <bits/stdc++.h>
using namespace std;

long long memo[65];

void generateNumber(int n) {
    memo[0] = 1;
    for(int i=1;i<61;i++) {
        if (i%2 != 0) {
            memo[i] = 2 * memo[i-1];
        } else {
            memo[i] = 1 + memo[i-1];
        }
    }
}

int main() {
    int t;
    cin>>t;
    generateNumber(60);
    while(t--) {
        int n;
        cin>>n;
        cout<<memo[n]<<endl;
    }
    return 0;
}