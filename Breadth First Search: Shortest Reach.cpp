#include <bits/stdc++.h>
using namespace std;

map<int, vector<int> > graph;
map<int, int> visited;

void bfs(int from, int target) {
    queue<int> q;
    visited[from] = 0;
    q.push(from);

    while(!q.empty()){
        int curr = q.front();
        q.pop();

        for(int i=0;i<graph[curr].size();i++){
            int node = graph[curr][i];
            if (!visited.count(node)) {
                visited[node] = visited[curr] + 1;
                q.push(node);
            }
        }
    }
}

int main() {
    int n;
    cin>>n;
    while(n--) {
        int vertex, edge;
        cin>>vertex>>edge;
        for(int i=0;i<edge;i++){
            int from, to;
            cin>>from>>to;
            graph[from].push_back(to);
            graph[to].push_back(from);
        }
        int start;
        cin>>start;
        bfs(start, vertex);
        for(int i=1;i<=vertex;i++){
            if (i == start) {
                continue;
            }
            if (visited[i] == 0) {
                cout<<"-1 ";
            } else {
                cout<<visited[i]*6<<" ";
            }
        }
        cout<<endl;
        visited.clear();
        graph.clear();
    }
    return 0;
}