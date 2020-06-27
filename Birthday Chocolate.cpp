#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    vector<int> arr;
    cin>>n;
    while(n--) {
        int input;
        cin>>input;
        arr.push_back(input);
    }
    int d, m;
    cin>>d>>m;
    vector<int> ways;
    ways.push_back(arr[0]);
    int sum = arr[0];
    for(int i=1;i<arr.size();i++) {
        sum += arr[i];
        ways.push_back(sum);
    }
    int result = 0;
    for(int i=m;i<=ways.size();i++) {
        if (ways[i-1] - ways[i-m-1] == d) {
            result++;
        }
    }
    cout<<result<<endl;
    return 0;
}