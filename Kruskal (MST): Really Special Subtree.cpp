#include <bits/stdc++.h>
using namespace std;

map<int, int> parent;

void generateParent(int n) {
    for(int i=1;i<=n;i++) {
        parent[i] = i;
    }
}

int findParent(int n) {
    if (parent[n] == n) {
        return n;
    }
    return findParent(parent[n]);
}

bool isParentSame(int a, int b) {
    return findParent(a) == findParent(b);
}

void mergeParent(int a, int b){
    parent[findParent(b)] = findParent(a);
}

int main() {
    int v,e;
    cin>>v>>e;
    vector< pair<int, pair<int,int> > > graph;
    generateParent(e);
    while(e--) {
        int from, to, weight;
        cin>>from>>to>>weight;
        graph.push_back(make_pair(weight, make_pair(from, to)));
        graph.push_back(make_pair(weight, make_pair(to, from)));
    }
    sort(graph.begin(), graph.end());
    int cost = 0;
    for(int i=0;i<graph.size();i++) {
        pair<int, pair<int,int> > edge = graph[i];
        if (!isParentSame(edge.second.first, edge.second.second)) {
            mergeParent(edge.second.first, edge.second.second);
            cost += edge.first;
        }
    }
    cout<<cost<<endl;
    return 0;
}