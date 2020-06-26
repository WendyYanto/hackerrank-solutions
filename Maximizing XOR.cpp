#include <bits/stdc++.h>
using namespace std;

int max(int a, int b) {
    if (a>b) {
        return a;
    }
    return b;
}

int main() {
    int from, to;
    cin>>from>>to;
    int output = 0;
    for(int i=from;i<=to;i++) {
        for(int j=i;j<=to;j++) {
            output = max(output, i^j);
        }
    }
    cout<<output<<endl;
    return 0;
}