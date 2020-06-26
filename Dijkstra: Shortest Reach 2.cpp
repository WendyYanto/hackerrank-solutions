#include <bits/stdc++.h>
using namespace std;
# define INF 0x3f3f3f3f 

map <long long, vector<pair<long long, long long> > > graph;
map <int, bool> visited;
int weight[3001];

void dijkstra(int start) {
    priority_queue< pair<long long, long long> ,vector< pair<long long, long long>  >,greater< pair<long long, long long>  > > queue;
    weight[start] = 0;
    queue.push(make_pair(0, start));
    while(!queue.empty()) {
        pair<int, int> curr = queue.top();
        int curr_weight = weight[curr.second];
        queue.pop();
        // To avoid duplicate visited vertex
        if (visited[curr.second]) continue;
        visited[curr.second] = true;
        for(int i=0;i<graph[curr.second].size();i++) {
            pair<int, int> neighbour = graph[curr.second][i];
            int v = neighbour.first;
            int w = neighbour.second;
            if (!visited[v]) {
                if (weight[v] > (curr_weight + w)) {
                    weight[v] = (curr_weight + w);
                    queue.push(make_pair(weight[v], v));
                }
            }
        }   
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
      cin.tie(nullptr);
  cout.tie(nullptr);
    int t;
    cin>>t;
    while(t--) {
        long long n, e;
        cin>>n>>e;
        for(int i=0;i<e;i++) {
            int from, to, w;
            cin>>from>>to>>w;
            graph[from].push_back(make_pair(to, w));
            graph[to].push_back(make_pair(from, w));
        }
        for(int i=0;i<=n;i++) {
            weight[i] = INF;
        }
        int start;
        cin>>start;
        dijkstra(start);
        for(int i=1;i<=n;i++) {
            if (i == start) {
                continue;
            }
            if (weight[i] != INF) {
                cout<<weight[i];
            } else {
                cout<<-1;
            }
            if (i <= n - 1) {
                cout<<" ";
            }
        }
        cout<<"\n";
        graph.clear();
        visited.clear();
    }
    return 0;
}