#include <iostream>
using namespace std;

int gcd(int a, int b){
	if(b==0){
		return a;
	}
	return gcd(b, a%b);
}

int main(){
	int n;
	cin>>n;
	int numbers[n+1];
	for(int i=0;i<n;i++){
		cin>>numbers[i];
	}
	int count = 0;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			int output;
			output = gcd(numbers[i], numbers[j]);
			if (output != 1 && output%2 == 1){
				count++;
			}
		}
	}
	cout<<count;
	return 0;
}
