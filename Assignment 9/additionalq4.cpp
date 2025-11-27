#include <bits/stdc++.h>
using namespace std;

void dfs(int x, int y, vector<vector<char>>& g) {
    int m = g.size(), n = g[0].size();
    if (x<0 || y<0 || x>=m || y>=n || g[x][y] == '0') return;

    g[x][y] = '0';

    dfs(x+1,y,g);
    dfs(x-1,y,g);
    dfs(x,y+1,g);
    dfs(x,y-1,g);
}

int main() {
    vector<vector<char>> grid = {
        {'1','1','0'},
        {'0','1','0'},
        {'1','0','1'}
    };

    int m = grid.size(), n = grid[0].size();
    int count = 0;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == '1') {
                count++;
                dfs(i,j,grid);
            }
        }
    }

    cout << count;
}
