#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, divisor;
    cin>>n>>divisor;
    int numbers[n+1];
    for (int i=0;i<n;i++){
        cin>>numbers[i];
    }
    int counter = 0;
    for(int i=0;i<n;i++) {
        for(int j=i+1;j<n;j++) {
            if ((numbers[i] + numbers[j])%divisor == 0) {
                counter++;
            }
        }
    }
    cout<<counter<<endl;
    return 0;
}