#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, d;
  cin>>n>>d;
  map<int, bool> number;
  vector<int> datum;
  while(n--) {
    int input;
    cin>>input;
    datum.push_back(input);
    number[input] = true;
  }
  int output = 0;
  for(int i=0;i<datum.size();i++) {
    int curr = datum[i];
    int next = number[curr + d];
    int next_of_next = number[curr + d + d];
    if (next && next_of_next) {
      output++;
    }
  }
  cout<<output<<endl;
  return 0;
}