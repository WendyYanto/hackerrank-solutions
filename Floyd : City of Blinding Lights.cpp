#include <bits/stdc++.h>
using namespace std;
# define INF 0x3f3f3f3f 

map <long long, vector<pair<int, int> > > graph;
map <int, bool> visited;
int weight[505][505];

void dijkstra(int node, int start) {
    priority_queue< pair<int, int> ,vector< pair<int, int>  >,greater< pair<int, int>  > > queue;
    weight[node][start] = 0;
    queue.push(make_pair(0, start));
    while(!queue.empty()) {
        pair<int, int> curr = queue.top();
        int curr_weight = weight[node][curr.second];
        queue.pop();
        visited[curr.second] = true;
        for(int i=0;i<graph[curr.second].size();i++) {
            pair<int, int> neighbour = graph[curr.second][i];
            int v = neighbour.first;
            int w = neighbour.second;
            if (!visited[v]) {
                if (weight[node][v] > (curr_weight + w)) {
                    weight[node][v] = (curr_weight + w);
                    queue.push(make_pair(weight[node][v], v));
                }
            }
        }   
    }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int v,e;
  cin>>v>>e;
  map < int , map <int, int > > temp;
  while(e--) {
    int from, to, weight;
    cin>>from>>to>>weight;
    temp[from][to] = weight;
  }
  for(auto const& from: temp) { 
    map <int, int> inner_map = from.second;
    int begin = from.first;
    for (auto const to: inner_map) {
      int end = to.first;
      int weight = to.second;
      graph[begin].push_back(make_pair(end, weight));
    }
  }
  for(int i=0;i<501;i++) {
    for(int j=0;j<501;j++) {
      weight[i][j] = INF;
    }
  }
  for(int i=1;i<=v;i++) {
    dijkstra(i, i);
    visited.clear();
  }
  int q;
  cin>>q;
  while(q--) {
    int from, to;
    cin>>from>>to;
    if (weight[from][to] == INF) {
      cout<<-1<<endl;
    } else {
      cout<<weight[from][to]<<endl;
    }
  }
  return 0;
}
