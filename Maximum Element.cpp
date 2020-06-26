#include <bits/stdc++.h>
using namespace std;

long max(long a, long b) {
  if (a>b) {
    return a;
  }
  return b;
}

int main() {
  int n;
  cin>>n;
  stack< pair<long, long> > s;
  while(n--) {
    long input;
    cin>>input;
    if (input == 1) {
      long number;
      cin>>number;
      if (s.empty()) {
        // Initial Max
        s.push(make_pair(number, number));
      } else {
        // Compare current number to previous max
        // If higher then set max of current interval to curr number
        // If lower then set max of current interval same as previous
        long curr_max = max(number, s.top().second);
        s.push(make_pair(number, curr_max));
      }
    } else if (input == 2) {
      s.pop();
    } else if (input == 3) {
      // Achieve By O(1)
      cout<<s.top().second<<endl;
    }
  }
  return 0;
}