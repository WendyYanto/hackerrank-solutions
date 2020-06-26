#include <bits/stdc++.h>
using namespace std;

map<int, int> transport;
map<int, int> visited;

int bfs(int start) {
    queue<int> q;
    q.push(start);
    visited[start] = 0;
    while(!q.empty()) {
        int curr = q.front();
        q.pop();
        if (curr == 100) {
            return visited[curr];
        }
        for(int i=1;i<=6;i++) {
            int next = curr+i;
            if (next > 100) {
                continue;
            }
            if (!visited.count(next)) {
                // set current + i as visited
                visited[next] = 1 + visited[curr];
                if (transport[next] != 0) {
                    // set next ladder/snakes as visited
                    visited[transport[next]] = 1 + visited[curr];
                    q.push(transport[next]);
                } else {
                    q.push(next);
                }
            }
        }
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--) {
        int ladder;
        cin>>ladder;
        for(int i=0;i<ladder;i++) {
            int from,to;
            cin>>from>>to;
            transport[from] = to;
        }
        int snake;
        cin>>snake;
        for(int i=0;i<snake;i++) {
            int from, to;
            cin>>from>>to;
            transport[from] = to;
        }
        // cout<<"Traversing"<<endl;
        cout<<bfs(1)<<endl;
        transport.clear();
        visited.clear();
    }
    return 0;
}