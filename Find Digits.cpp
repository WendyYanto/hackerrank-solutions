#include <bits/stdc++.h>
using namespace std;

long getDivisors(long n) {
    long curr = n;
    long output = 0;
    while(curr != 0) {
        int digit = curr % 10;
        if (digit != 0) {
            if (n % digit == 0) {
                output++;
            }
        }
        curr /= 10;
    }
    return output;
}

int main() {
    int n;
    cin>>n;
    while(n--){
        long input;
        cin>>input;
        cout<<getDivisors(input)<<endl;
    }
}