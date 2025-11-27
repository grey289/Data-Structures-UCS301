#include <bits/stdc++.h>
using namespace std;

struct Edge { int u,v,w; };

int findP(int x, vector<int>& parent) {
    if (parent[x] == x) return x;
    return parent[x] = findP(parent[x], parent);
}

void unionSet(int a, int b, vector<int>& parent, vector<int>& rank) {
    a = findP(a, parent);
    b = findP(b, parent);
    if (a == b) return;
    if (rank[a] < rank[b]) parent[a] = b;
    else if (rank[b] < rank[a]) parent[b] = a;
    else parent[b] = a, rank[a]++;
}

int main() {
    vector<Edge> edges = {
        {0,1,4}, {0,2,1}, {1,2,2}, {1,3,5}, {2,3,3}
    };
    int V = 4;

    sort(edges.begin(), edges.end(), [](auto &a, auto &b){
        return a.w < b.w;
    });

    vector<int> parent(V), rank(V, 0);
    for (int i = 0; i < V; i++) parent[i] = i;

    int mst = 0;
    for (auto &e : edges) {
        if (findP(e.u, parent) != findP(e.v, parent)) {
            mst += e.w;
            unionSet(e.u, e.v, parent, rank);
        }
    }
    cout << "MST Weight = " << mst;
}
