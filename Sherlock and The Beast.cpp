#include <bits/stdc++.h>
using namespace std;

void calculateDecentNumber(int n) {
    // z = 3y + 5x;
    // y is (total digits of 5);
    // x is (total digits of 3);
    // This is greedy because we want to take the biggest first
    // The biggest is of course start with 5 and digits of 5 
    // which means y should be the biggest and x is the smallest
    int y;
    int x = 0;
    bool flag = false;
    while(true) {
        if (flag) {
            break;
        }
        y = n - 5*x;
        if (y < 0) {
            break;
        }
        if (y%3==0) {
            // If total digits of 5 (y) divisible by 3 
            // The print 
            // and done
            for(int i=0;i<y;i++){
                cout<<5;
            }
            for(int i=0;i<5*x;i++) {
                cout<<3;
            }
            cout<<endl;
            flag = true;
        } 
        x++;
    }
    if (!flag) {
        cout<<-1<<endl;
    }
}

int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        if (n<=2) {
            cout<<-1<<endl;
        } else {
            calculateDecentNumber(n);
        }

    }
    return 0;
}