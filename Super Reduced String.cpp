#include <bits/stdc++.h>
using namespace std;

string reducedString(string input){
	if (input == "") {
		return "Empty String";
	}
	for (int i = 0;i<input.length() - 1;i++) {
		if (input[i] == input[i+1]) {
			input.erase(i, 2);
			return reducedString(input);
		}
	}
	return input;
}

int main(){
	string input;
	cin>>input;
	cout<<reducedString(input)<<endl;
	return 0;
}
