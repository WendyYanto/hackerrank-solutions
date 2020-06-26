#include <bits/stdc++.h>
using namespace std;

unsigned long long countValues(unsigned long long n) 
{ 
    int unset_bits=0; 
    while (n > 0) { 
        if ((n & 1L) == 0) {
            unset_bits++;
        }
        n=n>>1L; 
    } 

    return 1L << unset_bits;
} 

int main() {
    unsigned long long n;
    cin>>n;
    cout<<countValues(n)<<endl;
    return 0;
}