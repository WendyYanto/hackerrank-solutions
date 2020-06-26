#include <bits/stdc++.h>
using namespace std;

map<long long , vector <long long> > graph;
map<long long , long long > visited;

int R = 2;

long long dfs(long long index) {
    visited[index] = true;
    int nodes = 0;
    for(long long i=0;i<graph[index].size();i++) {
        int n = graph[index][i];
        if (!visited[n]) {
            nodes += dfs(n);
        }
    }
    return 1 + nodes;
}

long long combination(long long n) {
    if (n == 1) {
        return 1/2;
    }
    return n * (n-1) / R;
}

int main() {
    // Logic is calculate combination of all number
    // Then minus combination of equal nodes
    int v,e;
    cin>>v>>e;
    while(e--) {
        long long from, to;
        cin>>from>>to;
        graph[from].push_back(to);
        graph[to].push_back(from);
    }
    long long result = combination(v);
    for(int i=0;i<v;i++) {
        int count = 0;
        if (!visited[i]) {
            count = dfs(i);
        }
        result -= combination(count);
    }
    cout<<result<<endl;
    return 0;
}