#include <bits/stdc++.h>
using namespace std;

bool isValid(long a, long b, long c) {
  // If it is no-degenerate triagle 
  // Then the sum of 2 smaller side should be greater than largest side
  // c is the largest because it is sorted
  if (a + b > c) return true;
  return false;
}

long max(long a, long b) {
  if (a>b) return a;
  return b;
} 

int main() {
  int n;
  cin>>n;
  vector<long> data;
  int temp = n;
  while(temp--){
    long input;
    cin>>input;
    data.push_back(input);
  }
  sort(data.begin(), data.end());
  // Sliding window 
  long final = LONG_MIN;
  long index = -1;
  for(int i=2;i<n;i++) {
    long a = data[i-2];
    long b = data[i-1];
    long c = data[i];
    if (!isValid(a, b, c)) {
      continue;
    };
    long sum = a + b + c;
    if (final <= sum) {
      index = i-2;
      final = sum;
    }
  }
  if (final == LONG_MIN) {
    cout<<-1<<endl;
  } else {
    for(int i=index;i<=index+2;i++) {
      cout<<data[i]<<" ";
    }
    cout<<endl;
  }
  return 0;
}