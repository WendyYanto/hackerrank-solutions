#include <bits/stdc++.h>
using namespace std;

int dp[5001][5001];

int max(int a, int b) {
  if (a>b) {
    return a;
  }
  return b;
}

int lcs(string first, string second, int n, int m) {
  for(int i=0;i<=n;i++) {
    for(int j=0;j<=m;j++) {
      if (i == 0 || j == 0) {
        dp[i][j] = 0;
      } else if (first[i-1] == second[j-1]) {
        dp[i][j] = dp[i-1][j-1] + 1;
      } else {
        dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
      }
    }
  }
  return dp[m][n];
}

int main() {
  string first, second;
  cin>>first>>second;
  cout<<lcs(first, second, first.length(), second.length());
  return 0;
}