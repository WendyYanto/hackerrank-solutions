#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long n, r;
  cin>>n>>r;
  vector<long long> data;
  long long output = 0;
  map<long long, long long> left_map, right_map;
  for(long long i=0;i<n;i++) {
    long long input;
    cin>>input;
    data.push_back(input);
    right_map[input]++;
  }
  for(long long i=0;i<n;i++) {
    long long curr = data[i];
    right_map[curr]--;
    if (curr % r == 0) {
      // Need to make sure if it is valid geometric to R
      output += (left_map[curr/r] * right_map[curr*r]);
    }
    left_map[curr]++;
  }
  cout<<output<<endl;
  return 0;
}