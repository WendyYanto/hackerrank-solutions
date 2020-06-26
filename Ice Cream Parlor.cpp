#include<bits/stdc++.h> 
using namespace std;

int main() {
    int test_case, money, n;
    cin>>test_case;
    while(test_case--) {
        cin>>money;
        cin>>n;
        int numbers[n+1];
        for(int i=0;i<n;i++){
            cin>>numbers[i];
        }
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++) {
                if (numbers[i] + numbers[j] == money) {
                    cout<<i+1<<" "<<j+1<<endl;
                    break;
                }
            }
        }
    }    
    return 0;
}