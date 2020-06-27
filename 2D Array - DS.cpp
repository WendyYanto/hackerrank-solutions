#include <iostream>
using namespace std;

int max(int a, int b){
	if(a>b){
		return a;
	}
	return b;
}

int main(){
	int output = -9999999;
	int array[6][6];
	
	for(int i=0;i<6;i++){
		for(int j=0;j<6;j++){
			cin>>array[i][j];
		}
	}
	
	for(int i=1;i<=4;i++){
		for(int j=1;j<=4;j++){
			output = max(output, array[i-1][j-1] + array[i-1][j] + array[i-1][j+1]
			+ array[i][j] + array[i+1][j-1] + array[i+1][j] + array[i+1][j+1]);
		}
	}
	
	cout<<output;
	return 0;
}