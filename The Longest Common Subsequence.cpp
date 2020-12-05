#include <bits/stdc++.h>
using namespace std;

vector<int> firstNumbers;
vector<int> secondNumbers;

map< pair<int, int>, pair<int,int> > bestState;

int memo[1005][1005];

int dp(int i, int j) {
  if (i >= firstNumbers.size() || j >= secondNumbers.size()) {
    return 0;
  }
  if (memo[i][j] != -1) {
    return memo[i][j];
  }
  if (firstNumbers[i] == secondNumbers[j]) {
    bestState[make_pair(i, j)] = make_pair(i+1, j+1);
    return memo[i][j] = 1 + dp(i+1, j+1);
  }
  int firstOption = dp(i+1, j);
  int secondOption = dp(i, j+1);
  pair<int, int> currentPosition = make_pair(i, j);
  if (firstOption > secondOption) {
    bestState[currentPosition] = make_pair(i+1, j);
    return memo[i][j] = firstOption;
  } else {
    bestState[currentPosition] = make_pair(i, j+1);
    return memo[i][j] = secondOption;
  }
}

int main() {
  int n, m, input;
  cin>>n>>m;
  memset(memo, -1, sizeof(memo));
  for(int i=0;i<n;i++) {
    cin>>input;
    firstNumbers.push_back(input);
  }
  for(int i=0;i<m;i++) {
    cin>>input;
    secondNumbers.push_back(input);
  }
  // Traversing with D
  dp(0,0);
  // Backtracking
  pair<int,int> current = make_pair(0, 0);
  while(bestState.count(current) != 0) {
    pair<int, int> nextState = bestState[current];
    if (current.first != nextState.first && current.second != nextState.second) {
      cout<<firstNumbers[current.first]<<" ";
    }
    current = nextState;
  }
  return 0;
}