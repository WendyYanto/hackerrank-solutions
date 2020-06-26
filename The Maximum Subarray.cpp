#include <bits/stdc++.h>
using namespace std;

int max(int a, int b) {
    if (a>b) {
        return a;
    }
    return b;
}

int calculateMaxSubsequence(vector<int> arr) {
    int sum = 0;
    for(int i=0;i<arr.size();i++) {
        if (arr[i] >= 0) {
            sum += arr[i];
        }
    }
    if (sum == 0) {
        sum = arr[0];
        for(int i=1;i<arr.size();i++) {
            sum = max(sum, arr[i]);
        }
    }
    return sum;
}

int calculateSum(vector<int> arr) {
    // Kadane’s Algorithm
    int max_so_far = INT_MIN, max_ending_here = 0; 
    for (int i = 0; i < arr.size(); i++) { 
        max_ending_here = max_ending_here + arr[i];
        if (max_so_far < max_ending_here) {
            // Found the maximum recurrent sum
            // maximumSubarraySum will end at this index
            max_so_far = max_ending_here; 
        }

        if (max_ending_here < 0) {
            // Ignore if the current sum if already negative
            // Reset it into zero
            // Which means the start of maximumSubarraySum is next index;
            max_ending_here = 0;
        }
    } 
    return max_so_far; 
}

int main() {
    int n;
    cin>>n;
    while(n--) {
        int size;
        cin>>size;
        vector<int> arr;
        while(size--) {
            int input;
            cin>>input;
            arr.push_back(input);
        }
        cout<<calculateSum(arr)<<" "<<calculateMaxSubsequence(arr)<<endl;
    }
    return 0;
}