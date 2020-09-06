#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin>>n;
  vector<int> data;
  int index = 0;
  while(index < n) {
    int input;
    cin>>input;
    data.push_back(input);
    index++;
  }
  sort(data.begin(), data.end());
  int output = 1;
  int maxWeight = data[0] + 4;
  for(int i=1;i<n;i++) {
    if (data[i] > maxWeight) {
      output++;
      maxWeight = data[i] + 4;
    } 
  }
  cout<<output<<endl;
  return 0;
}