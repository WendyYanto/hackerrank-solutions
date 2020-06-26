#include <iostream>
using namespace std;

int calculate(int n){
	if (n < 38 || n%5 == 0){
		return n;
	} else {
		int round = (n / 5) + 1;
		if (((round * 5) - n) < 3) {
			return round*5;
		}else{
			return n;
		}
	}
}

int main(){
	int n;
	cin>>n;
	int array[n+1];
	int x;
	for(int i=0;i<n;i++){
		cin>>x;
		cout<<calculate(x)<<endl;
	}
	return 0;
}
