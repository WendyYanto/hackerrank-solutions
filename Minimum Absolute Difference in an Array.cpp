#include <bits/stdc++.h>
using namespace std;

int absolute(int a){
    if(a<0) {
        return -a;
    }
    return a;
}

int min(int a, int b){
    if(a>b){
        return b;
    }
    return a;
}

int main() {
    int n;
    cin>>n;
    vector<int> arr;
    while(n--) {
        int q;
        cin>>q;
        arr.push_back(q);
    }
    sort(arr.begin(), arr.end());
    int result = INT_MAX;
    for(int i=0;i<arr.size() - 1; i++) {
        result = min(result, absolute(arr[i] - arr[i+1]));
    }
    cout<<result<<endl;
    return 0;
}