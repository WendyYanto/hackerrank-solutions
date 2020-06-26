#include <bits/stdc++.h>
using namespace std;

long long getSum(long long curr){
    if (curr/10 != 0) {
        // calculate sum
        int output = 0;
        while(curr != 0) {
            output += curr%10;
            curr/=10;
        }
        return getSum(output);
    } 
    return curr;
}

int main(){
    string n;
    long long k;
    cin>>n>>k;
    long long num = 0;
    // traverse string into number 
    for(int i=0;i<n.length();i++) {
        int curr = n[i] - '0';
        num += curr;
    }
    cout<<getSum(num*k)<<endl;
    return 0;
}