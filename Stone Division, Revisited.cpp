#include <bits/stdc++.h>
using namespace std;

vector<long long> queries;
map<long long, long long> dp;

long long max(long long a, long long b) {
  if (a>b) {
    return a;
  }
  return b;
}

bool isNotDivisible(long long count, long long query) {
  // cannot be divided and should not be equal
  return (count % query != 0) || count == query;
}

// top bottom dp
long long solve(long long countOfStones) {
  if (countOfStones <= 1) {
    // base case because all number can be divided by 0 and 1
    return 0;
  }
  if (dp[countOfStones] != 0) {
    // if cache present then no need to calculate again
    return dp[countOfStones];
  }
  long long maxCount = 0;
  // start from all queries and recursively evaluate again
  for (long long i=0;i<queries.size();i++) {
    long long query = queries[i];
    // if it cannot divided then skip to next query
    if (isNotDivisible(countOfStones, query)) {
      continue;
    }
    // get total piles of remaining stones after divided by query
    long long countOfDividedStonesByQuery = countOfStones / query;
    // get calculate current query and evaluate again until it reach base case
    long long sumOfNextDivisionByRemainingStones = countOfDividedStonesByQuery * solve(query);
    // add one to sum because dividing action performed
    long long sum = 1 + sumOfNextDivisionByRemainingStones;
    // save if it the max actions performed at countOfStones
    maxCount = max(maxCount, sum);
  }
  // cache solutions by countOfStones as key
  dp[countOfStones] = maxCount;
  return maxCount;
}

int main() {
  int t;
  cin>>t;
  while(t--) {
    long long countOfStones, countOfQueries;
    cin>>countOfStones>>countOfQueries;
    for(int i=0;i<countOfQueries;i++) {
      long long query;
      cin>>query;
      queries.push_back(query);
    }
    cout<<solve(countOfStones)<<endl;
    // clear cache for next test case
    queries.clear();
    dp.clear();
  }
  return 0;
}