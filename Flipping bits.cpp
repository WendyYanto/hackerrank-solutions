#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    vector<unsigned int> cases;
    for(int i=0;i<t;i++) {
        unsigned int input;
        cin>>input;
        cases.push_back(input);
    }
    for(int i=0;i<t;i++) {
        cout<<~cases[i]<<endl;
    }
    return 0;
}