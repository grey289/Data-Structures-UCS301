#include <bits/stdc++.h>
using namespace std;

int main() {
    int V = 5;
    vector<vector<pair<int,int>>> adj(V);

    auto add = [&](int u, int v, int w){
        adj[u].push_back({v,w});
    };

    add(0,1,4); add(0,2,1);
    add(2,1,2); add(1,3,1); add(2,3,5);

    vector<int> dist(V, INT_MAX);
    dist[0] = 0;

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0,0});

    while (!pq.empty()) {
        auto [d,u] = pq.top(); pq.pop();
        if (d > dist[u]) continue;

        for (auto &p : adj[u]) {
            int v = p.first, w = p.second;
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    for (int d : dist) cout << d << " ";
}
