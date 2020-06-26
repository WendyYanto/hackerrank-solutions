#include <bits/stdc++.h>
using namespace std;

int main() {
// 4 1
// 3 10 2 9
// 12
    int n, index;
    cin>>n>>index;
    int count = 0;
    for(int i=0;i<n;i++) {
        int input;
        cin>>input;
        if (i != index) {
            count += input;
        }
    }
    int bill;
    cin>>bill;
    count /= 2;
    int diff = bill - count;
    if (diff == 0) { 
        cout<<"Bon Appetit"<<endl;
    } else {
        cout<<diff<<endl;
    }
    return 0;
}