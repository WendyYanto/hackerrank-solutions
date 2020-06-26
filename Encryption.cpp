#include <bits/stdc++.h>
using namespace std;

int main() {
  string input;
  cin>>input;
  double root = sqrt(input.length());
  int row = floor(root);
  int col = ceil(root);
  if (row*col < input.length()) {
    row = col;
  }
  char output[81][81];
  int x = 0;
  int y = 0;
  for(int i=0;i<input.length();i++){
    output[y][x] = input[i];
    x++;
    if ((i+1)%(col)==0) {
      x = 0;
      y++;
    } 
  }
  string ans;
  for(int i=0;i<col;i++) {
    for(int j=0;j<row;j++) {
      if (output[j][i] != '\0') {
        cout<<output[j][i];
      } 
    }
    if (i < col-1) {
      cout<<" ";
    }
  }
  cout<<endl;
  return 0;
}