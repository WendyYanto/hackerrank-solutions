#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,k,q;
    cin>>n>>k>>q;
    int numbers[n+1];
    for(int i=0;i<n;i++) {
        cin>>numbers[i];
    }
    k %= n;
    int rotated[n+1];
    int index = 0;
    int start = n - k;
    for(int i=start;i<n;i++){
        rotated[index] = numbers[i];
        index++;   
    }
    for(int i=0;i<start;i++){
        rotated[index] = numbers[i];
        index++;   
    }
    while(q--) {
        int input;
        cin>>input;
        cout<<rotated[input]<<endl;
    }
    return 0;
}