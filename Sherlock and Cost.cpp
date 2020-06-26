#include <bits/stdc++.h>
using namespace std;

int dp[100001][1001];

int absolute(int a){
    if(a<0){
        return -a;
    }
    return a;
}

int max(int a, int b){
    if(a>b){
        return a;
    }
    return b;
}

int generateMaxDiffArray(int array[], int index, int currTarget){    
    if(index==0){
        return 0;    
    }
    
    if(dp[index][currTarget] != -1){
        return dp[index][currTarget];
    }
    
    return dp[index][currTarget] = max(
        generateMaxDiffArray(array, index-1, array[index-1]) + absolute(currTarget-array[index-1]),
        generateMaxDiffArray(array, index-1, 1) + absolute(currTarget-1)
    );
}    

int main(){
    int n;
    cin>>n;
    while(n--){
        int count;
        cin>>count;
        int array[count+1];
        for(int i=0;i<count;i++){
            cin>>array[i];
        }
        for(int i=0; i<=100000;i++){
            for(int j=0;j<=1000;j++){
                dp[i][j] = -1;
            }
        }
        cout<<max(generateMaxDiffArray(array, count - 1, array[count-1]), generateMaxDiffArray(array, count - 1, 1))<<endl;
    }
    return 0;
}
