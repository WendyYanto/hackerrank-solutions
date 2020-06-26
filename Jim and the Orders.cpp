#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    int s,d;
    cin>>n;
    // pair->first = total time
    // pair->second = no. customer
    vector< pair<int,int> > order;
    for(int i=0;i<n;i++) {
        cin>>s>>d;
        order.push_back(make_pair(s+d,i+1));
    }
    sort(order.begin(), order.end());
    for(int i=0;i<n;i++){
        cout<<order[i].second;
        if (i < (n-1)) {
            cout<<" ";
        }
    }
    cout<<endl;
    return 0;
}