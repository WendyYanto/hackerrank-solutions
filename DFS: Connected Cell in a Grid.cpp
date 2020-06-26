#include <bits/stdc++.h>
using namespace std;

int n,m;
int box[11][11];
bool visited[11][11];

int vertical[] = {1,-1,0,0,1,1,-1,-1};
int horizontal[] = {0,0,1,-1,1,-1,1,-1};

int traverse(int x, int y) {
    int count = 0;
    int row, col;
    if (visited[x][y]) {
        return 0;
    }
    if (box[x][y] == 1) {
        count += 1;
    }
    visited[x][y] = true;
    for(int i=0;i<8;i++){
        int row = horizontal[i] + x;
        int col = vertical[i] + y;
        if (row < 0 || col < 0 || row == n || col == m ) continue;
        if (box[row][col] == 1) {
            count += traverse(row, col);
        }
    }
    return count;
}

int max(int a, int b){
    if(a>b){
        return a;
    }
    return b;
}

int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>box[i][j];
            visited[i][j] = false;
        }
    }

    int output = 0;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) {
            if (box[i][j] == 1){
                if (!visited[i][j]) {
                    output = max(output, traverse(i, j));
                }
            }
        }
    }

    cout<<output<<endl;

    return 0;
}