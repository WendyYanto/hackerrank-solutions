#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin>>n;
  string s = "";
  stack< string > action;
  while(n--) {
    int input;
    int data;
    string word;
    cin>>input;
    if (input == 1) {
      cin>>word;
      action.push(s);
      s += word;
    } else if (input == 2) {
      cin>>data;
      int n = s.size() - data;
      action.push(s);
      s.erase(n, data);
    } else if (input == 3) {
      cin>>data;
      cout<<s[data-1]<<endl;
    } else if (input == 4) {
      if(!action.empty()) {
        s = action.top();
        action.pop();
      }
    }
  }
  return 0;
}