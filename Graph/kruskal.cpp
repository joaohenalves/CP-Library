int parent[MAX], nodeRank[MAX];
vector<tiii> edges;

int findSet(int u) {
    if(parent[u] == u) return u;
    return parent[u] = findSet(parent[u]);
}

void unionSets(int u, int v) {
    u = findSet(u);
    v = findSet(v);
    if(nodeRank[u] > nodeRank[v]) {
        parent[v] = u;
    } else {
        parent[u] = v;
        if(nodeRank[v] == nodeRank[u]) nodeRank[v]++;
    }
}

int kruskal() {
    int ans = 0, t = n;
    fill(nodeRank, nodeRank + n, 0);
    iota(parent, parent + n, 0);
    sort(edges.begin(), edges.end());
    for(auto &[u, v, w] : edges) {
        if(findSet(u) != findSet(v)) {
            ans += w;
            unionSets(u, v);
            t--;
        }
    }
    return t == 1 ? ans : -1;
}
