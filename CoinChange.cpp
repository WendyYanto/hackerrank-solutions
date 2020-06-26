#include <bits/stdc++.h>
#include <cstring>
using namespace std;
long dp[12501][51];

long coinChange(long numbers[], long index, long target){

	if(target<0 || index<0){
		return 0;
	}
	
	if(dp[target][index] != -1){
		return dp[target][index];
	}
	
	if(target == 0){
		return 1;
	}
	
	return dp[target][index] = (coinChange(numbers, index, target-numbers[index]) +
			coinChange(numbers, index - 1, target)
		);
}

int main(){
	int n, target;
	cin>>target>>n;
	long numbers[n+1];
	for(int i=0;i<n;i++){
		cin>>numbers[i];
	}
	for(long i=0;i<12501;i++){
		for(long j=0;j<51;j++){
			dp[i][j] = -1;
		}
	}
	cout<<coinChange(numbers, n-1, target)<<endl;
	return 0;
}
