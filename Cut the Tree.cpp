#include <bits/stdc++.h>
using namespace std;

long long weight[100005];
map<int, vector<long> > graph;
map<int, bool> visited;
long long node_sum[100005];

long long absolute(long long a) {
    if (a<0) {
        return -a; 
    }
    return a;
}

long long min(long long a, long long b) {
    if (a>b){
        return b;
    }
    return a;
}

long long dfs(long long index) {
    visited[index] = true;
    long long sum = 0;
    for(int i=0;i<graph[index].size();i++) {
        int n = graph[index][i];
        if(!visited[n]) {
            sum += dfs(n);
        }
    }
    return node_sum[index] = sum + weight[index];
}

int main() {
    int n;
    cin>>n;
    int total_vertex = n;
    long long total_weight = 0;
    for(int i=1;i<=n;i++) {
        cin>>weight[i];
        total_weight += weight[i];
    }
    n-=1;
    while(n--) {
        int from, to;
        cin>>from>>to;
        graph[from].push_back(to);
        graph[to].push_back(from);
    }
    dfs(1);
    long long output = INT_MAX;
    for(int i=2;i<=total_vertex;i++) {
        long long opposite = total_weight - node_sum[i];
        output = min(output, absolute(opposite - node_sum[i]));
    }
    cout<<output<<endl;
    return 0;
}