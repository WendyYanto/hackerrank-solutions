#include<bits/stdc++.h> 
using namespace std;

int main() {
    int n;
    cin>>n;
    int numbers[n+1];
    for(int i=0;i<n;i++){
        cin>>numbers[i];
    }
    sort(numbers, numbers+n);
    long long exponential = 1;
    long long result = 0;
    for(int i=n-1;i>=0;i--){
        result += (numbers[i]*exponential);
        exponential*=2;
    }
    cout<<result<<endl;
    return 0;
}