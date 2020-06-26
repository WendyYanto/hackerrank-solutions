#include <bits/stdc++.h>
using namespace std;

int grid[11][11] = {0};
int visited[11][11] = {0};
int row, col;

int max(int a, int b) {
    if (a>b) {
        return a;
    }
    return b;
}

int floodfill(int x, int y) {
    if (x < 0 || y < 0 || x == row || y == col || grid[x][y] == 0 || visited[x][y] == -1) {
        return 0;
    } 
    visited[x][y] = -1;
    return 1 + floodfill(x+1, y) + floodfill(x-1, y) + floodfill(x, y+1) + floodfill(x, y-1)
             + floodfill(x+1, y+1) + floodfill(x+1, y-1) + floodfill(x-1, y+1) + floodfill(x-1, y-1)
    ;
}

int main() {
    cin>>row>>col;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++) {
            cin>>grid[i][j];
        }
    }
    int maximum = INT_MIN;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++) {
            if (grid[i][j] == 1) {
                maximum = max(maximum, floodfill(i,j));   
            }
        }
    }
    cout<<maximum<<endl;
    return 0;
}