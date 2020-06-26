#include <bits/stdc++.h>
using namespace std;

int max(int a, int b){
    if (a>b) {
        return a;
    }
    return b;
}

int main() {
    int n;
    cin>>n;
    map<int, int> birds;
    set<int> data;
    while(n--) {
        int input;
        cin>>input;
        birds[input]++;
    }
    int output = -INT_MAX;
    int name = -1;
    // Log N Solution
    for(auto const& bird : birds) {
        if (bird.second > output)  {
            output = bird.second;
            name = bird.first;
        }
    }
    cout<<name<<endl;
}