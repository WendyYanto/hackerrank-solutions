#include <bits/stdc++.h>
using namespace std;

vector<int> solutions;
int target = -1;

bool solve(int curr, int index, int choices[], int k) {
    if (curr == target) {
        solutions.push_back(0);
        return true;
    }
    if (index == k) {
        return false;
    }
    if (curr > target) {
        return false;
    }
    solutions.push_back(curr);
    if (solve(curr, index+1, choices, k)) {
        return true;
    }
    solutions.pop_back();
    solutions.push_back(curr*choices[index]);
    if (solve(curr*choices[index], index+1, choices, k)) {   
        return true;
    }
    solutions.pop_back();
    return false;
}

int main() {
    int n,k;
    cin>>n>>k;
    int choices[k+1];
    for(int i=0;i<k;i++) {
        cin>>choices[i];
    }
    target = n;
    // sort(choices, choices+k);
    if (solve(1, 0, choices, k)) {
        for(int i=0;i<solutions.size();i++) {
            cout<<solutions[i]<<" ";
        }
    } else {
        cout<<-1<<endl;
    }
    return 0;
}