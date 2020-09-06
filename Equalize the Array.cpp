#include <bits/stdc++.h>
using namespace std;

int max(int a, int b) {
  if (a>b) return a;
  return b;
}

int main() {
  int n;
  cin>>n;
  map<int, int> data;
  int index = 0;
  while(index < n) {
    int input;
    cin>>input;
    data[input]++;
    index++;
  }
  int maxDuplicate = INT_MIN;
  for(auto item = data.begin(); item != data.end(); item++) {
    if (item->second > maxDuplicate) {
      maxDuplicate = item->second;
    } 
  }
  cout<<n-maxDuplicate<<endl;
  return 0;
}