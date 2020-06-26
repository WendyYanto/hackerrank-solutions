#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    int numbers[n+1];
    int importance[n+1];
    int sum = 0;
    int temp;
    int important_index = 0;
    for(int i=0;i<n;i++){
        cin>>numbers[i];
        cin>>temp;
        if (temp == 1) {
            importance[important_index] = numbers[i];
            important_index++;
        }
        sum += numbers[i];
    }
    sort(importance, importance + important_index);
    int decrementer = 0;
    for(int i=0;i<(important_index-m);i++){
        decrementer += importance[i];
    }
    cout<<sum - (2 * decrementer)<<endl;
    return 0;
}