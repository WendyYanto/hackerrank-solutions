#include <bits/stdc++.h>
using namespace std;

int MOD = 1000000007;

long long int solveByDP(string number, long long int length) {
    long long int dp[200005];
    dp[0] = 1;
    for(long long int i=1;i<200005;i++) {
        dp[i] = (dp[i-1] * 10 + 1)%MOD;
    }
    long long int result = 0;
    for(long long int i=0;i<length;i++) {
        result += ((((number[i] - '0')*dp[length-i-1])%MOD)*(i+1))%MOD;
    }
    return result%MOD;
}

int main() {
    string number;
    cin>>number;
    long long int output = 0;
    long long int length = number.length();
    long long int k = 1;
    // 123
    // 1 + 2 + 3 + 12 + 23 + 123
    // 1 => 111 * 1 => 111 * 1 * 1
    // 2 => 22 * 2  => 11  * 2 * 2
    // 3 => 3 * 3 =>    1  * 3 * 3
    // for(int i=length - 1;i>=0;i--) {
    //     output += ((((number[i] - '0')*k))*(i+1))%MOD;
    //     k = (k*10+1)%MOD;
    // }
    cout<<solveByDP(number, length)<<endl;
    // cout<<output%MOD<<endl;
    return 0;
}