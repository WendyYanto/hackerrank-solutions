#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

int main() {
    int n, target;
    int count = 0;
    cin>>n>>target;
    int numbers[n+1];
    for(int i=0;i<n;i++){
        cin>>numbers[i];
    }
    sort(numbers, numbers + n);
    int i = 0;
    int j = 1;
    while(i < n) {
        int diff = (numbers[j] - numbers[i]);
        if (diff == target) {
            count++;
            i++;
        } else if (diff < target) {
            j++;
        } else if (diff > target) {
            i++;
        }
    }
    cout<<count<<endl;
    return 0;
}