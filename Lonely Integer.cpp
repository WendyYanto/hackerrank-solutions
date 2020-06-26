#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    map<int, int> data;
    cin>>n;
    while(n--) {
        int input;
        cin>>input;
        data[input]++;
    }
    for (auto const& i: data) {
        if (i.second == 1) {
            cout<<i.first<<endl;
            break;
        }
    }
    return 0;
}