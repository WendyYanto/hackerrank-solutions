#include <bits/stdc++.h>
using namespace std;

// Give Up 
// To Do

bool prime[50];
bool memo[100];

long long threeP = 0;
long long fourP = 0;
long long fiveP = 0;

// Solutions should precompute all sum 3 -5 
// Then traverse

void generatePrimes() {
    // Sieve of Erastothenes
    memset(prime, true, sizeof(prime));
    memset(memo, true, sizeof(memo));
    prime[1] = false;
    prime[0] = false;
	for(int i=2;i*i<=50;i++){
		if(prime[i]){
			for(int j=i*i;j<=50;j+=i){
				prime[j] = false;
			}
		}
	}
}

bool checkPrimeSum(string number, int n) {
    for(int i=0;i<n;i++) {
        // 3 digit
        if (i+2 < n) {
            int first = (number[i] - '0' );
            int second = (number[i+1] - '0');
            int third = (number[i+2] - '0');
            int total = first + second + third;
            // Check memo exist or not
            if (!memo[total]) {
                return false;
            }
            if (!prime[total]) {
                memo[total] = false;
                return false;
            } 
            // 4 Digit
            if (i+3 < n) {
                int fourth = (number[i+3] - '0');
                int total = first + second + third + fourth;
                if (!memo[total]) {
                    return false;
                }
                if (!prime[total]) {
                    memo[total] = false;
                    return false;
                }
                // 5 Digit
                if (i+4 < n) {
                    int fifth = (number[i+4] - '0');
                    int total = first + second + third + fourth + fifth;
                    if (!memo[total]) {
                        return false;
                    }
                    if (!prime[total]) {
                        memo[total] = false;
                        return false;
                    }
                }
            }
        } 

    }
    return true;
}

// void traverse(int digit) {
//     int n = digit;
//     digit -= 1;
//     long long start = 1;
//     long long end = 9;
//     while(digit--) {
//         start *= 10;
//         end *= 10;
//         end += 9;
//     }   
//     long long count = 0;
//     for(long long i=start;i<=end;i++) {
//         if(checkPrimeSum(to_string(i), n)) {
//             count++;
//         }
//     }
    
//     cout<<count<<endl;
// }

void precompute() {
    // for(int i=100;i<=999;i++) {
    //     if (checkPrimeSum(to_string(i), 3)) {
    //         cout<<i<<endl;
    //         threeP++;
    //     }
    // }   
    // for(int i=1000;i<=9999;i++) {
    //     if (checkPrimeSum(to_string(i), 4)) {
    //         fourP++;
    //     }
    // }
    // for(int i=10000;i<=99999;i++) {
    //     if (checkPrimeSum(to_string(i), 5)) {
    //         fiveP++;
    //     }
    // }
    long long hehe = 0;
    for(int i=100000;i<=999999;i++) {
        if(checkPrimeSum(to_string(i), 6)) {
            hehe++;
        }
    }
    cout<<"hehe "<<hehe<<endl;
}

int main() {
    int n;
    generatePrimes();
    precompute();
    cout<<threeP<<" "<<fourP<<" "<<fiveP<<endl;
    // cin>>n;
    // while(n--) {
    //     int input;
    //     cin>>input;
    //     // 6
    //     // 1 2 3 4 5 6
        
    //     long long output = 0;
    //     for(int i=1;i<=input;i++) {
    //         if (i+2 <= input) {
    //             output += threeP;
    //         }
    //         if (i+3 <= input) {
    //             output += fourP;
    //         }
    //         if (i+4 <= input) {
    //             output += fiveP;
    //         }
    //     }
    //     cout<<output<<endl;
    // }
}