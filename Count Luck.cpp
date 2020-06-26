#include <bits/stdc++.h>
using namespace std;

int action_x[] = {-1, 0, 1, 0};
int action_y[] = {0, -1, 0, 1};
char forest[101][101];

// ACCEPTED FINALLY

map < pair<int, int>, bool > visited;
map < pair<int, int>, pair<int, int> > path;

void bfs(int start_x, int start_y, int target_x, int target_y, int n, int m) {
    queue<pair<int, int> > q;
    pair<int, int> start = make_pair(start_x, start_y);
    q.push(start);
    visited[start] = true;
    int output = 0;
    while(!q.empty()) {
        pair<int, int> curr = q.front();
        q.pop();
        int choice = 0;

        if (curr.first == target_x && curr.second == target_y) {
            return;
        }

        for(int i=0;i<4;i++) {
            int next_x = action_x[i] + curr.first;
            int next_y = action_y[i] + curr.second;
            if (next_x < 0 || next_y < 0 || next_x >= m || next_y >= n) {
                continue;
            }
            pair<int, int> next = make_pair(next_x, next_y);
            if (forest[next_y][next_x] == '.' || forest[next_y][next_x] == '*') {
                if (!visited[next]) {
                    visited[next] = true;
                    path[next] = curr;
                    q.push(next);
                }
            }
        }
    }
    return;
}

int main() {
    int t;
    cin>>t;
    vector<string> answer;
    while(t--) {
        int n,m;
        cin>>n>>m;
        int start_x, start_y;
        int target_x, target_y;
        char input;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                cin>>input;
                if (input == 'M') {
                    start_x = j;
                    start_y = i;
                } else if (input == '*') {
                    target_x = j;
                    target_y = i;
                }
                forest[i][j] = input;
            }
        }
        int predict;
        cin>>predict;
        bfs(start_x, start_y, target_x, target_y, n, m);
        int result = 0;
        // Traverse back shortest path 
        pair<int, int> target = make_pair(target_x, target_y);
        pair<int, int> curr = target;
        pair<int, int> start = make_pair(start_x, start_y);
        visited[target] = false;
        while(curr != start) {
            int n = 0;
            for(int i=0;i<4;i++) {
                int next_x = action_x[i] + curr.first;
                int next_y = action_y[i] + curr.second;
                if (forest[next_y][next_x] == '.' || forest[next_y][next_x] == 'M') {
                    if (visited[make_pair(next_x, next_y)]) {
                        n++;
                        visited[make_pair(next_x, next_y)] = false;
                    }
                }
            }
            if (n >= 2) {
                result++;
            }
            curr = path[curr];
        }
        // curr is now start
        // We need this to know all neighbor when attempting first step
        n = 0;
        for(int i=0;i<4;i++) {
            int next_x = action_x[i] + curr.first;
            int next_y = action_y[i] + curr.second;
            if (forest[next_y][next_x] == '.' || forest[next_y][next_x] == '*') {
                n++;
            }
        }
        if (n >= 2) {
            result++;
        }
        if (result == predict) {
            cout<<"Impressed"<<endl;
        } else {
            cout<<"Oops!"<<endl;
        }
        visited.clear();
        // Clear Forest to avoid edge case 
        for(int i=0;i<101;i++) {
            for(int j=0;j<101;j++) {
                forest[i][j] = 'X';
            }
        }
    }
    return 0;
}