#include <bits/stdc++.h>
using namespace std;

int absolute(int a){
    if (a<0){
        return -a;
    }
    return a;
}

int main() {
    int n;
    cin>>n;
    int arrays[n+1][n+1];
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++){
            cin>>arrays[i][j];
        }
    }
    int left = 0;
    int right = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if (i==j) {
                left += arrays[i][j];
            }
            if (i+j == (n-1)) {
                right += arrays[i][j];
            }
        }
    }
    cout<<absolute(left-right)<<endl;
    return 0;
}