#include <bits/stdc++.h>
using namespace std;

map <int, vector <int> > graph;
map <int, bool > visited;

int answer = 0;

int dfs(int index) {
    visited[index] = true;
    int nodes = 0;
    for(int i=0;i<graph[index].size();i++) {
        int neighbour = graph[index][i];
        if (!visited[neighbour]) {
            // Get Children's Total Node
            // Recursively this will first validate the lowest node of tree
            // That's why answer will grow
            int next_nodes = dfs(neighbour);
            // If Children's Node already even then separate it 
            if (next_nodes % 2 == 0) {
                answer++;
            } else {
            // If Not even then add it to process next by root of its children
                nodes += next_nodes;
            }
        } 
    }
    // Add + 1 For current nodes 
    return nodes + 1;
}

int main() {
    int e,v;
    cin>>e>>v;
    while(v--) {
        int from, to;
        cin>>from>>to;
        graph[from].push_back(to);
        graph[to].push_back(from);
    }
    dfs(1);
    cout<<answer<<endl;
    return 0;
}