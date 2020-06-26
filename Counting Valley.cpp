#include <bits/stdc++.h>
using namespace std;

int countingValleys(int n, string s) {
    int counter = 0;
    int walker = 0;
    for (int i=0;i<n;i++) {
        if (s[i] == 'U') {
            walker--;
        } else if (s[i] == 'D') {
            walker++;
        }
        if (walker == 0 && s[i]=='U') {
            // If already balance and current path is going up
            // Then update counter
            counter++;
        }
    }
    return counter;
}

int main() {
    int n;
    cin>>n;
    string path;
    cin>>path;
    cout<<countingValleys(n, path)<<endl;
    return 0;
}