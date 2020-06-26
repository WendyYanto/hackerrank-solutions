#include <bits/stdc++.h>
using namespace std;

int generateSquare(int from, int to) {
    return floor(sqrt(to)) - ceil(sqrt(from)) + 1;
}

int main() {
    int n;
    cin>>n;
    while(n--) {
        int from, to;
        cin>>from>>to;
        cout<<generateSquare(from, to)<<endl;
    }
    return 0;
}