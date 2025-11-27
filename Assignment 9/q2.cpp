#include <bits/stdc++.h>
using namespace std;

void dfsUtil(int u, vector<vector<int>>& adj, vector<bool>& vis) {
    vis[u] = true;
    cout << u << " ";

    for (int v : adj[u]) {
        if (!vis[v]) dfsUtil(v, adj, vis);
    }
}

int main() {
    int V = 6;
    vector<vector<int>> adj = {
        {1,2}, {0,3}, {0,3}, {1,2,4}, {3,5}, {4}
    };

    vector<bool> vis(V, false);
    dfsUtil(0, adj, vis);
    return 0;
}
