#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    int number[n+1];
    for(int i=0;i<n;i++) {
        cin>>number[i];
    }
    sort(number, number + n);
    int low = 0;
    int high = n - 1;
    int mid = (low + high) / 2;
    cout<<number[mid]<<endl;
    return 0;
}