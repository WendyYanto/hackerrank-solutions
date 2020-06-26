#include <bits/stdc++.h>
using namespace std;

int min(int a, int b) {
    if (a>b) {
        return b;
    }
    return a;
}

int knapsack(int index, int n, int sacks[], int target) {
    if (index == n) {
        return target;
    }
    if (target < 0) {
        return INT_MAX;
    }
    if (target == 0) {
        return 0;
    } 
    return min(knapsack(index, n, sacks, target-sacks[index]),
        knapsack(index+1, n, sacks, target));
}

int main() {
    int n;
    cin>>n;
    while(n--) {
        int count, target;
        cin>>count>>target;
        int sacks[count+1];
        for(int i=0;i<count;i++) {
            cin>>sacks[i];
        }
        cout<<target - knapsack(0, count, sacks, target)<<endl;
    }
    return 0;
}