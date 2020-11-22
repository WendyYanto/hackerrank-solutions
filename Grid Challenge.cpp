#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin>>t;
  while(t--) {
    int n;
    cin>>n;
    char input;
    map<int, vector<int> > grid;
    for(int i=0;i<n;i++) {
      for(int j=0;j<n;j++) {
        cin>>input;
        grid[i].push_back(input - 'a');
      }
    }
    for(int i=0;i<n;i++) {
      sort(grid[i].begin(), grid[i].end());
    }
    bool isSorted = true;
    for(int i=0;i<=n-1;i++) {
      for(int j=0;j<n-1;j++) {
        if (grid[j][i] > grid[j+1][i]) {
          isSorted = false;
          break;
        }
      }
    }
    if (isSorted) {
      cout<<"YES"<<endl;
    } else {
      cout<<"NO"<<endl;
    }
  }
  return 0;
}