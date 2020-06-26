#include<bits/stdc++.h> 
using namespace std;

int main() {
    int n,k;
    cin>>n>>k;
    int numbers[n+1];
    for(int i=0;i<n;i++) {
        cin>>numbers[i];
    }
    sort(numbers, numbers + n);
    int i = 0;
    int transmitters = 0;
    while (i<n) {
        // Create one transmitter
        transmitters++;
        // Find The Center of transmittter
        int center_of_trasmitter = numbers[i] + k;
        while(i<n && numbers[i]<=center_of_trasmitter) {
            // Go To Next Index Until It is more 1 index of the center of transmitter
            i++;
        }
        //Because it is more than one index of the center -> substract the i
        i--;
        // Find The End of Transmitter
        int end_of_transmitter = numbers[i] + k;
        while(i<n && numbers[i]<=end_of_transmitter) {
            // Go To Next Index Until It is more 1 index of the end of transmitter
            // to create new transmitter
            i++;
        }
    }
    cout<<transmitters<<endl;
    return 0;
}