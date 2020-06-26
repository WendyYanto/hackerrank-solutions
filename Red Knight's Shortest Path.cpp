#include <bits/stdc++.h>
using namespace std;

map< pair<int, int>, bool> visited;
vector< pair<int, int> > walk;
vector<string> description;
map< pair<int, int>, pair<int, int> > path;
map< pair<int, int>, string> reach;

bool bfs(int row, int col, int target_y, int target_x, int n) {
    queue< pair<int, int> > q;
    pair<int, int> curr = make_pair(row,col);
    q.push(curr);
    visited[curr] = true;
    while(!q.empty()) {
        pair<int, int> coor = q.front();
        q.pop();
        int row = coor.first;
        int col = coor.second;
        if (row < 0 || col < 0 || row >= n || col >= n){
            continue;
        }
        if (row == target_y && col == target_x) {
            return true;
        }
        visited[coor] = true;
        for(int i=0;i<walk.size();i++) {
            pair<int, int> action = walk[i];
            int next_y = action.second + row;
            int next_x = action.first + col;
            pair<int, int> next = make_pair(next_y, next_x);
            if(!visited[next]) {
                // Only take if only this position never visited before [first come first serve]
                if (!path.count(next)) {
                    path[next] = coor;
                    reach[next] = description[i];
                    q.push(next);
                }
            }
        }
    }
    return false;
}

int main() {
    int n;
    cin>>n;
    int x, y, target_x, target_y;
    cin>>y>>x>>target_y>>target_x;
    // col row
    walk.push_back(make_pair(-1, -2));
    description.push_back("UL");
    walk.push_back(make_pair(1, -2));
    description.push_back("UR");
    walk.push_back(make_pair(2, 0));
    description.push_back("R");
    walk.push_back(make_pair(1, 2));
    description.push_back("LR");
    walk.push_back(make_pair(-1, 2));
    description.push_back("LL");
    walk.push_back(make_pair(-2, 0));
    description.push_back("L");
    if(bfs(y,x,target_y,target_x,n)) {
        pair<int, int> curr = make_pair(target_y, target_x);
        pair<int, int> begin = make_pair(y, x);
        vector<string> output;
        while (curr != begin) {
            output.push_back(reach[curr]);
            curr = path[curr];
        }
        int size = output.size();
        cout<<size<<endl;
        for(int i=size - 1; i>=0; i--) {
            cout<<output[i];
            if (i > 0) {
                cout<<" ";
            }
        }
    } else {
        cout<<"Impossible"<<endl;
    }
    return 0;
}