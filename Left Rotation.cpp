#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, rotation;
    cin>>n>>rotation;
    int numbers[n+1];
    for(int i=0;i<n;i++) {
        cin>>numbers[i];
    }
    rotation %= n;
    for (int i=rotation;i<n;i++) {
        cout<<numbers[i]<<" ";
    }
    for (int i=0;i<rotation;i++){
        cout<<numbers[i]<<" ";
    }
    cout<<endl;
    return 0;
}