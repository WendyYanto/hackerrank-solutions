#include <bits/stdc++.h>
using namespace std;

bool isPangrams(string input) {
  map<int, int> data;
  for(int i=0;i<input.length();i++){
    data[tolower(input[i]) - 'a']++;
  }
  for(int i=0;i<=25;i++) {
    if (!data.count(i)) {
      return false;
    }
  }
  return true;
}

int main() {
  string input;
  getline(cin,input);
  if (!isPangrams(input)) {
    cout<<"not ";
  }
  cout<<"pangram"<<endl;
  return 0;
}