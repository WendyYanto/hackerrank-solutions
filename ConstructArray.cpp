#include <bits/stdc++.h>
using namespace std;

long long n,k,x;

// To Do

long long countArray(long long maximumNumber, long long maximumIndex, long long finalNumber) {
    vector<long long> a(maximumIndex + 1), b(maximumIndex + 1);
    
    //A IS POSSIBILITY OF ENDING WITH FINALNUMBER
    //B IS POSSIBILITY OF NOT ENDING WITH FINALNUMBER

    if (finalNumber == 1) {
        a[0] = 1;
        b[0] = 0; 
    } else {
        a[0] = 0;
        b[0] = 1; 
    }

    for(int i=1;i<n;i++){
        a[i] = b[i-1]%1000000007;
        b[i] = ((a[i-1]*(maximumNumber - 1)) + (b[i-1]*(maximumNumber - 2)))%1000000007;
    }

    return a[maximumIndex - 1];
}

int main() {
    cin>>n>>k>>x;
    cout<<countArray(k, n, x)<<endl;
    return 0;
}