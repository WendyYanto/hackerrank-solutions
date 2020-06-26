#include <bits/stdc++.h>
using namespace std;

long long min(long long a, long long b) {
    if (a<b) {
        return a;
    }
    return b;
}

int main() {
    int n,k;
    cin>>n>>k;
    vector<long long> numbers;
    for(int i=0;i<n;i++) {
        long long input;
        cin>>input;
        numbers.push_back(input);
    }
    sort(numbers.begin(), numbers.end());
    long long result = LONG_MAX;
    for(int i=0;i<=(numbers.size()-k);i++) {
        result = min(result, (numbers[i+k-1] - numbers[i]));
    }
    cout<<result<<endl;
    return 0;
}