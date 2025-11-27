#include <bits/stdc++.h>
using namespace std;

void BFS(int start, vector<vector<int>>& adj) {
    int n = adj.size();
    vector<bool> vis(n, false);
    queue<int> q;

    vis[start] = true;
    q.push(start);

    while (!q.empty()) {
        int u = q.front(); q.pop();
        cout << u << " ";

        for (int v : adj[u]) {
            if (!vis[v]) {
                vis[v] = true;
                q.push(v);
            }
        }
    }
}

int main() {
    int V = 6;
    vector<vector<int>> adj = {
        {1,2}, {0,3}, {0,3}, {1,2,4}, {3,5}, {4}
    };

    BFS(0, adj);
    return 0;
}
