// https://www.youtube.com/watch?v=CTng83luuo4

#include <bits/stdc++.h>
using namespace std;

long long max(long long a, long long b) {
    if (a>b) {
        return a;
    }
    return b;
}

int main() {
    int n;
    cin>>n;
    long long number[n+1];
    long long candies[n+1];
    for(int i=0;i<n;i++) {
        cin>>number[i];
    }
    for(int i=0;i<n;i++) {
        candies[i] = 1;
    }
    // Compare to left
    // if is higher than left 
    // then add one candy
    for(int i=1;i<n;i++) {
        if (number[i] > number[i-1]) {
            candies[i] = candies[i-1] + 1;
        }
    }
    // Compare to right
    // if is higher than right 
    // then add one candy
    // then compare get the maximum value of both
    for(int i=(n-2);i>=0;i--) {
        if (number[i] > number[i+1]) {
            candies[i] = max(candies[i+1] + 1,  candies[i]);
        }
    }

    long long result = 0;
    for(int i=0;i<n;i++) {
        result += candies[i];
    }
    cout<<result<<endl;
    return 0;
}