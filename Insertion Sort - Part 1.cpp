#include <bits/stdc++.h>
using namespace std;

void print(int n, int arr[]) {
    for(int i=0;i<n;i++) {
        cout<<arr[i];
        if(i < n-1) {
            cout<<" ";
        }
    }
    cout<<endl;
}

void insertionSort(int n, int arr[]) {
    int i,j,value;
    for(i=1;i<n;i++) {
        value = arr[i];
        j = i-1;
        while(j>=0 && arr[j] > value) {
            arr[j+1] = arr[j];
            print(n, arr);
            j = j-1;
        }
        arr[j+1] = value;
    }
    print(n, arr);
}

int main(void) {

    int N;
    scanf("%d", &N);
    int arr[N], i;
    for(i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    insertionSort(N, arr);

    return 0;
}