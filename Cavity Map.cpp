#include <bits/stdc++.h>
using namespace std;

vector<string> traverse(vector<string> grid) {
  for(int i=1;i<grid.size()-1;i++) {
    for(int j=1;j<grid[i].length()-1;j++) {
      int top = grid[i-1][j] - '0';
      int bottom = grid[i+1][j] - '0';
      int left = grid[i][j-1] - '0';
      int right = grid[i][j+1] - '0';
      int curr = grid[i][j] - '0';
      if (curr > top && curr > left && curr > right && curr > bottom ) {
        grid[i][j] = 'X';
      }
    }
  }
  return grid;
}

int main() {
  int n;
  cin>>n;
  vector<string> grid;
  for(int i=0;i<n;i++) {
    string word;
    cin>>word;
    grid.push_back(word);
  }
  vector<string> output = traverse(grid);
  for(int i=0;i<n;i++) {
    cout<<output[i]<<endl;
  }
  return 0;
}