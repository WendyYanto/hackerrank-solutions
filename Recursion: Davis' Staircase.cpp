#include <bits/stdc++.h>
// #include <iostream>
using namespace std;

int dp[36];

int generatePossible(int n){
    if (dp[n] != -1) {
        return dp[n];
    }
    if (n==0){
        return 1;
    }
    if (n<0) {
        return 0;
    } 
    return dp[n] = generatePossible(n-1) + generatePossible(n-2) + generatePossible(n-3);
}

int main(){
    int n;
    cin>>n;
    for(int i=0;i<37;i++){
        dp[i] = -1;
    }
    while(n--) {
        int input;
        cin>>input;
        cout<<generatePossible(input) <<endl;
    }
    return 0;
}