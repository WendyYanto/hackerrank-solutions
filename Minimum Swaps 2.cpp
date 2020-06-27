#include <bits/stdc++.h>
using namespace std;

// 3 4 2 5 1
// 1 2 3 4 5

int main () {
  int n;
  cin>>n;
  vector< pair<int, int> > lists;
  for(int i=0;i<n;i++) {
    int number;
    cin>>number;
    lists.push_back(make_pair(number, i));
  }
  sort(lists.begin(), lists.end());
  int output = 0;
  map<int, bool> visited;
  for(int i=0;i<n;i++) {
    pair<int, int> curr = lists[i];
    int index = curr.second;
    int num = curr.first;
    if (index == i || visited[index]) {
      continue;
    } else {
      int cycle = 0;
      pair<int, int> next = lists[index];
      while(index != next.second) {
        visited[next.second] = true;
        next = lists[next.second];
        cycle++;
      }
      output += (cycle-1);
    }
  }
  cout<<output<<endl;
  return 0;
}