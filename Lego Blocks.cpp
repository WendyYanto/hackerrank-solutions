#include <bits/stdc++.h>
using namespace std;

// To Do

int MOD = 1000000007;

long long int blockWays[1001];
long long int square[1001][1001];

long long int ways(long long int n) {
    if (blockWays[n] != -1) {
        return blockWays[n];
    }
    if (n < 0) {
        return 0;
    }
    if (n==0) {
        return 1;
    }
    return blockWays[n] =  (ways(n-1) + ways(n-2) + ways(n-3) + ways(n-4)) % MOD;
}

long long int power(long long int n, long long int a) {
    if (square[n][a] != -1) {
        return square[n][a];
    }
    if (a == 1) {
        return square[n][1] = n;
    }
    if (a%2 == 0) {
        long long int x = power(n, a/2);
        return square[n][a] = (x*x)%MOD;
    } 
    return square[n][a] = n*power(n, a-1)%MOD;
}

int main() {
    int n;
    cin>>n;
    memset(square, -1, sizeof(square[0][0]) * 1000 * 1000);
    memset(blockWays, -1, sizeof(blockWays));
    while(n--){
        int width, height;
        cin>>height>>width;
        long long int shouldSubstract = 0;
        long long int total = power(ways(width)%MOD, height)%MOD;
        // Should substract minus solid wall 
        cout<<total<<endl;
    }
    return 0;
}
