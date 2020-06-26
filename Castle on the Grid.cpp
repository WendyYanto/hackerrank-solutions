#include <bits/stdc++.h>
using namespace std;

char graph[101][101];
int n;
map < pair<int, int>, int > visited;

int bfs(int startY, int startX, int goalY, int goalX) {
    queue< pair<int, int> > q;
    q.push(make_pair(startX, startY));
    visited[make_pair(startX, startY)] = 1;
    while(!q.empty()) {
        pair<int, int> curr = q.front();
        q.pop();
        if (curr.first == goalX && curr.second == goalY) {
            return visited[curr] - 1;
        }
        // to right
        for(int i=curr.first;i<n;i++) {
            int nextX = i;
            int nextY = curr.second;
            pair<int, int> next = make_pair(nextX, nextY);
            if (graph[nextY][nextX] == 'X') {
                break;
            }
            if (!visited.count(next)) {
                visited[next] = visited[curr] + 1;
                q.push(next);
            }
        }
        // to left
        for(int i=curr.first;i>=0;i--) {
            int nextX = i;
            int nextY = curr.second;
            pair<int, int> next = make_pair(nextX, nextY);
            if (graph[nextY][nextX] == 'X') {
                break;
            }
            if (!visited.count(next)) {
                visited[next] = visited[curr] + 1;
                q.push(next);
            }
        }
        // to top
        for(int i=curr.second;i>=0;i--) {
            int nextX = curr.first;
            int nextY = i;
            pair<int, int> next = make_pair(nextX, nextY);
            if (graph[nextY][nextX] == 'X') {
                break;
            }
            if (!visited.count(next)) {
                visited[next] = visited[curr] + 1;
                q.push(next);
            }
        }
        // to bottom
        for(int i=curr.second;i<n;i++) {
            int nextX = curr.first;
            int nextY = i;
            pair<int, int> next = make_pair(nextX, nextY);
            if (graph[nextY][nextX] == 'X') {
                break;
            }
            if (!visited.count(next)) {
                visited[next] = visited[curr] + 1;
                q.push(next);
            }
        }
    }
    return -1;
}

int main() {
    cin>>n;
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            cin>>graph[i][j];
        }
    }
    int startX, startY, goalX, goalY;
    cin>>startY>>startX>>goalY>>goalX;
    int output =  bfs(startY, startX, goalY, goalX);
    cout<<output<<endl;
    return 0;
}