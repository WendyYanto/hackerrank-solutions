#include <bits/stdc++.h>

using namespace std;

int smallestSizeSubsequence(int n, vector <int> A) {
    // Return the size of the smallest subsequence to remove
    int sum = 0;
    int oddCount = 0;
    for(int i=0;i<A.size();i++) {
        if (A[i] % 2 == 1) {
            oddCount++;
        }
        sum += A[i];
    }
    if (sum%2==0) {
        return 0;
    } else {
        if (oddCount >= 1) {
            if (A.size() == oddCount) {
                return -1;
            } else {
                return 1;
            }
        } else {
            return -1;
        }
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> A(n);
    for(int A_i = 0; A_i < n; A_i++){
    	cin >> A[A_i];
    }
    int result = smallestSizeSubsequence(n, A);
    cout << result << endl;
    return 0;
}
