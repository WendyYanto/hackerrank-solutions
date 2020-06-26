#include <bits/stdc++.h>
using namespace std;

bool prime[1000005]; 

int waysOfWall(int n) {
    if (n<0) {
        return 0;
    }
    if (n==0) {
        return 1;
    }
    return waysOfWall(n-4) + waysOfWall(n-1);
}

void generatePrime() {
    memset(prime, true, sizeof(prime));
    prime[0] = false;
    prime[1] = false;
    for(int i=2;i*i<=1000000;i++){
        if(prime[i]) {
            for(int j=i*i;j<=1000000;j+=i){
                prime[j] = false;
            }
        }
    }
}

int main() {
    int n;
    cin>>n;
    generatePrime();
    while(n--){
        int input;
        cin>>input;
        if (input <= 3) {
            cout<<0<<endl;
        } else {
            int output = waysOfWall(input);
            int count = 0;
            for(int i=2;i<=output;i++) {
                if(prime[i]) {
                    count++;
                }
            }
            cout<<count<<endl;
        }
    }
    return 0;
}