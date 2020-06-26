#include <bits/stdc++.h>
using namespace std;

int getPower(int n, int counter){
	int answer = n;
	for(int i=0;i<counter - 1;i++){
		answer = answer*n;
	}
	return answer;
}

int getPowerSum(int n, int number, int counter){
	if(n==0){
		return 1;
	}else if(n<0){
		return 0;
	}
	
	int decrementer = getPower(number, counter);
	if(decrementer > n){
		return 0;
	}
	
	return getPowerSum(n - decrementer, number + 1, counter) + 
			getPowerSum(n, number + 1, counter) ;
}

int main(){
	int n, counter;
	cin>>n>>counter;
	cout<<getPowerSum(n,1,counter)<<endl;
	return 0;
}
