#include <bits/stdc++.h>
using namespace std;

void insertionSort(int arr[], int n) {
    int j,value;
    int output = 0;
    for(int i=1;i<n;i++) {
        value = arr[i];
        j = i-1;
        int swap = 0;
        while(j>=0 && value < arr[j]) {
            arr[j+1] = arr[j];
            j = j-1;
            swap++;
        }
        arr[j+1] = value;
        output += swap;
    }
    cout<<output<<endl; 
}

int main() {
    int n;
    cin>>n;
    int arr[n+1];
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }
    insertionSort(arr, n);
    return 0;
}