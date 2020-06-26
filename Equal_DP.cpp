#include <bits/stdc++.h>

using namespace std;

int count = INT_MAX;

int min(int a, int b){
	if(a>b){
		return b;
	}
	return a;
}

int main(){
	int test_case;
	cin>>test_case;
	for(int i=0;i<test_case;i++){
		int n;
		cin>>n;
		int array[n+1];
		for(int i=0;i<n;i++){
			cin>>array[i];
		}
		int a = 0,b = 0,c = 0,d = 0,e = 0;
		int target = array[0];
		int targetIndex = 0;
		for(int i=1;i<n;i++){
			if(target > array[i]){
				target = array[i];
				targetIndex = i;
			}
		}
		int currIndex = 0;
		while(currIndex < n){
			if(currIndex != targetIndex){
				int count = array[currIndex] - (target);
				a += (count/5 + count%5/2 + count%5%2);	
			}
			currIndex++;
		}
		currIndex = 0;
		b += 1;
		while(currIndex < n){
			if(currIndex != targetIndex){
				int count = array[currIndex] - (target - 1);
				b += (count/5 + count%5/2 + count%5%2);
			}
			currIndex++;
		}
		currIndex = 0;
		c += 1;
		while(currIndex < n){
			if(currIndex != targetIndex){
				int count = array[currIndex] - (target - 2);
				c += (count/5 + count%5/2 + count%5%2);
			}
			currIndex++;
		}
		currIndex = 0;
		while(currIndex < n){
			if(currIndex != targetIndex){
				int count = array[currIndex] - (target - 3);
				d += (count/5 + count%5/2 + count%5%2);
			}
			currIndex++;
		}
		currIndex = 0;
		while(currIndex < n){
			if(currIndex != targetIndex){
				int count = array[currIndex] - (target - 4);
				e += (count/5 + count%5/2 + count%5%2);
			}
			currIndex++;
		}
		cout<<min(min(min(min(a,b),c),d),e)<<endl;
	}
	return 0;
}
