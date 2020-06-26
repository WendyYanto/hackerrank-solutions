#include<bits/stdc++.h> 
using namespace std;

void calculateMinimumBribes(int numbers[], int n){
    int count = 0;
    for(int i=0;i<n;i++) {
        // If current numbers is more than 2 the current position should have,
        // It is invalid because bribes to the front only takes place at most of 2
        if (numbers[i] - (i+1) > 2) {
            cout<<"Too chaotic"<<endl;
            return;
        }
        // Check maximum of 2 numbers ahead , this check valid
        // if only current numbers is in wrong position (smaller than positions -- take the bribe)
        // check if the traversing number is more thant the current number 
        for (int j=max(0, numbers[i] - 2);j<i;j++) {
            if (numbers[j] > numbers[i]) {
                count++;
            }
        }   
    }
    cout<<count<<endl;
}

int main() {
    int test;
    int n;
    cin>>test;
    while(test--) {
        cin>>n;
        int numbers[n+1];
        for(int i=0;i<n;i++){
            cin>>numbers[i];
        }
        calculateMinimumBribes(numbers, n);
    }
    return 0;
}