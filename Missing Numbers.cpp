#include<bits/stdc++.h> 
using namespace std;

int main() {
    int n,m;
    cin>>n;
    int firstNumbers[n+1];
    for(int i=0;i<n;i++) {
        cin>>firstNumbers[i];
    }
    cin>>m;
    int secondNumbers[m+1];
    for(int i=0;i<m;i++) {
        cin>>secondNumbers[i];
    }
    map< int,int > maps;
    for(int i=0;i<n;i++){
        maps[firstNumbers[i]]++;
    }
    for(int i=0;i<m;i++) {
        maps[secondNumbers[i]]--;
    }
    vector<int> invalidNums;
    for (auto i = maps.begin(); i != maps.end(); i++){
        if (i->second != 0) {
            invalidNums.push_back(i->first);
        }
    }
    sort(invalidNums.begin(), invalidNums.end());
    for (auto i : invalidNums) {
        cout<<i<<" ";
    }
    return 0;
}