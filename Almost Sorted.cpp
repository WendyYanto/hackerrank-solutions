#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin>>n;
  vector< pair<int, int> > data;
  for(int i=0;i<n;i++) {
    long input;
    cin>>input;
    data.push_back(make_pair(input, i));
  }
  sort(data.begin(), data.end());
  vector<int> diff;
  for(int i=0;i<n;i++) {
    if (data[i].second != i) {
      diff.push_back(i);
    }
  }
  // No difference
  if (diff.size() == 0) {
    cout<<"yes"<<endl;
    return 0;
  } 
  // Difference only two
  if (diff.size() == 2) {
    cout<<"yes"<<endl;
    cout<<"swap "<<diff[0]+1<<" "<<diff[1]+1<<endl;
    return 0;
  }
  // Difference is more than 2
  // Reverse to make it sorted
  reverse(data.begin() + diff[0], data.begin() + diff.back() + 1);
  bool good = true;
  // Check Again sorted or not
  for(int i=0;i<n;i++) {
    if (data[i].second != i) {
      // Case is that is need more than once reverse
      // It violates the rule
      good = false;
    }
  }
  if (good) {
    cout<<"yes"<<endl;
    cout<<"reverse "<<diff[0]+1<<" "<<diff.back()+1<<endl;
  } else {
    cout<<"no"<<endl;
  }
  return 0;
}