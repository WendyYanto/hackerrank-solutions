#include <bits/stdc++.h>
using namespace std;

int operations[] = {1,2,3};
int solution[10001];
int dp[10001][101];
// 10001 because max N is 10^4 [which is use for storing index]
// 101 because maximum remainder [x % 101] is 0 - 100 
bool solve(int numbers[], int remainder, int index, int n) {
    if (remainder == 0) {
        // if first 101 has been found  
        // it means 101 * x * y * z will always can be divided by 101
        // So there no need to find another 101 
        // Just traverse the next remainder index and add * 
        while(index < n) {
            solution[index] = 3;
            index++;
        } 
        return true;
    }
    // Has been flag means it will return false (see last line of this function)
    if (dp[index][remainder]) {
        return false;
    }
    if (index == n) {
        return remainder%101 == 0;
    } 
    // Always fetch remainder of 101
    if (solve(numbers, (remainder + numbers[index])%101, index+1, n)) {
        solution[index] = 1;
        return true;
    }
    if (solve(numbers, (remainder - (numbers[index]))%101, index+1, n)) {
        solution[index] = 2;
        return true;
    }
    if (solve(numbers, (remainder * (numbers[index]))%101, index+1, n)) {
        solution[index] = 3;
        return true;    
    }
    // Add flag so that not traversing again
    dp[index][remainder] = 1;
    return false;
}

int main() {
    int n;
    cin>>n;
    int numbers[n+1];
    for(int i=0;i<n;i++) {
        cin>>numbers[i];
    }
    solve(numbers, numbers[0] % 101, 1, n);
    cout<<numbers[0];
    for(int i=1;i<n;i++) {
        if (solution[i] == 1)  {
            cout<<"+";
        } else if (solution[i] == 2) {
            cout<<"-";
        } else if (solution[i] == 3) {
            cout<<"*";
        }
        cout<<numbers[i];
    }
    return 0;
}
