#include <bits/stdc++.h>
using namespace std;

int min(int a, int b){
    if(a<b){
        return a;
    }
    return b;
}

int main() {
    int n;
    cin>>n;
    vector< pair<long long, long long> > price;
    for(int i=0; i<n; i++){
        long long input;
        cin>>input;
        price.push_back(make_pair(input, i));
    }
    long long output = LONG_MAX;
    // Sort in order to get most minimum different between two number
    sort(price.begin(), price.end());
    for(int i=0;i<n - 1;i++) {
        // Can be use to compare with current minimum 
        // If only current original index is greater than the next original index
        if (price[i].second > price[i+1].second) {
            output = min(output, (price[i+1].first - price[i].first));
        }
    }
    cout<<output<<endl;
    return 0;
}