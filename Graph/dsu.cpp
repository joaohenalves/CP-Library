int parent[MAX], nodeRank[MAX];

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

void preprocess() {
    fill(nodeRank, nodeRank + n, 0);
    iota(parent, parent + n, 0);
}