#include <iostream>
using namespace std;

// index 
// target
long memo[12501][51];

long countWays(long coins[], int target, int n) {
    if (memo[target][n] != -1) {
        return memo[target][n];
    }
    if (n < 0 || target < 0) {
        return 0;
    }
    if (target == 0) {
        return 1;
    }
    if (target - coins[n] < 0) {
        return memo[target][n] = countWays(coins, target, n - 1);
    }
    return memo[target][n] = countWays(coins, target - coins[n], n) 
    + countWays(coins, target, n - 1);
}

int main() {
    int target, n;
    cin>>target>>n;
    long coins[n+1];
    for(int i=0;i<n;i++) {
        cin>>coins[i];
    }
    for(long i=0;i<12501;i++){
        for(long j=0;j<51;j++){
            memo[i][j] = -1;
        }
    }
    cout<<countWays(coins, target, n-1)<<endl;
    return 0;
}
