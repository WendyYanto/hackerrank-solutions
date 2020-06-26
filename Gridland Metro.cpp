#include <bits/stdc++.h>
using namespace std;

map<long long int, vector< pair<long long int, long long int> > > rows;
// Hint use this https://www.geeksforgeeks.org/merging-intervals/
// Pseudcode in merging overlapping interval
// 1. Sort the intervals based on increasing order of 
//     starting time.
// 2. Push the first interval on to a stack.
// 3. For each interval do the following
//    a. If the current interval does not overlap with the stack 
//        top, push it.
//    b. If the current interval overlaps with stack top and ending
//        time of current interval is more than that of stack top, 
//        update stack top with the ending  time of current interval.
// 4. At the end stack contains the merged intervals. 

long long int solve(vector< pair<long long int, long long int> > row) {
    sort(row.begin(), row.end());
    stack< pair<long long int, long long int> > s;
    s.push(row[0]);
    for(int i=1;i<row.size();i++) {
        pair<long long int, long long int> curr = s.top();
        // Not Overlap
        if (curr.second < row[i].first) {
            s.push(row[i]);
        } else if (curr.second < row[i].second) {
            // Overlap
            // if curr end is lesser 
            // Then merge
            curr.second = row[i].second;
            s.pop();
            s.push(curr);
        }
    }
    long long int total = 0;
    while(!s.empty()) {
        pair<long long int, long long int> curr = s.top();
        total += (curr.second - curr.first + 1);
        s.pop();
    }
    return total;
}

int main() {
    long long int n, m, k;
    cin>>n>>m>>k;
    long long int total = n*m;
    while(k--) {
        long long int row, from, to;
        cin>>row>>from>>to;
        rows[row].push_back(make_pair(from, to));
    }
    for(auto const& row: rows) {
        total -= solve(row.second);
    }
    cout<<total<<endl;
    return 0;
}