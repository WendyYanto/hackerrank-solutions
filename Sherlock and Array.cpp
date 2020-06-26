#include <bits/stdc++.h> 
using namespace std; 

string balancedSums(vector<int> arr) {
    vector<int> leftSum;
    vector<int> rightSum;
    leftSum.push_back(arr[0]);
    int sum = arr[0];
    for(int i=1;i<arr.size();i++) {
        sum += arr[i];
        leftSum.push_back(sum);
    }
    sum = arr[arr.size() - 1];
    rightSum.push_back(arr[arr.size() - 1]);
    for(int i=arr.size() - 2; i>=0;i--) {
        sum += arr[i];
        rightSum.push_back(sum);
    }
    reverse(rightSum.begin(), rightSum.end()); 
    for(int i=0;i<arr.size();i++) {
        if (leftSum[i] == rightSum[i]) {
            return "YES";
        }
    }
    return "NO";
}

int main() {
    int n;
    cin>>n;
    while(n--) {
        int count;
        cin>>count;
        vector<int> data;
        while(count--) {
            int input;
            cin>>input;
            data.push_back(input);
        }
        cout<<balancedSums(data)<<endl;
    }
}