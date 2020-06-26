#include <bits/stdc++.h>
using namespace std;

// ACC by raising complexity 

int max(int a, int b) {
  if (a > b) {
    return a;
  }
  return b;
}

int main() {
  int n, k;
  map<int, int> count;
  cin>>n>>k;
  string number[n+1];
  for(int i=0;i<n;i++) {
    cin>>number[i];
  }
  int output = INT_MIN;
  for(int i=0;i<n;i++) {
    for(int j=i+1;j<n;j++) {
      int counter = 0;
      for(int m=0;m<k;m++) {
        if (number[i][m] == '1' || number[j][m] == '1') {
          counter++;
        }
      }
      count[counter]++;
      output = max(output, counter);
    }
  }
  cout<<output<<endl;
  cout<<count[output]<<endl;
  return 0;
}
