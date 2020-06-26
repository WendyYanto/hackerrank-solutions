#include <bits/stdc++.h>
using namespace std;

int max(int a, int b) {
    if (a>b) {
        return a;
    }
    return b;
}

int main() {
    int n;
    cin>>n;
    int number[n+1];
    for(int i=0;i<n;i++) {
        cin>>number[i];
    }
    sort(number, number + n);
    int max_so_far = INT_MIN;
    int curr = 1;
    queue<int> q;
    q.push(number[0]);
    for(int i=1;i<n;i++) {
        // Current smallest
        int top = q.front();
        if (number[i] - top <= 1) {
            curr++;
        } else {
            curr = 1;
            q.pop();
            // set current number as smallest 
            // It will compare with number[i++]
            q.push(number[i]);
        }
        max_so_far = max(max_so_far, curr);
    }
    cout<<max_so_far<<endl;
    return 0;
}