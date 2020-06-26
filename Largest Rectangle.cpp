#include <bits/stdc++.h>
using namespace std;

long N = -1;
vector<long> arr;

long max(long a, long b) {
    if (a>b) {
        return a;
    }
    return b;
}

long goLeft(long index, long height) {
    long count = 0;
    if (index < 0) {
        return -1;
    }
    if (arr[index-1] >= height) {
        count = 1 + goLeft(index-1, height);
    } 
    return count;
}

long goRight(long index, long height) {
    long count = 0;
    if (index >= (N)) {
        return -1;
    }
    if (arr[index+1] >= height) {
        count = 1 + goRight(index+1, height);
    } 
    return count;
}

int main() {
    int n;
    cin>>n;
    while(n--){
        long input;
        cin>>input;
        arr.push_back(input);
    }
    N = arr.size();
    long output = INT_MIN;
    for(int i=0;i<N;i++) {
        long length = 1 + goLeft(i, arr[i]) + goRight(i, arr[i]);
        output = max(output, arr[i] * length);
    }
    cout<<output<<endl;
    return 0;
}