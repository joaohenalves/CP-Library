// maxDist contém para cada vértice, a maior distancia para outro vértice na árvore

int mx, maxDist[MAX];

void dfs(int u, int p, int d) {
    maxDist[u] = max(maxDist[u], d);
    if(d > mx) mx = d, m = u;
    for(int &v : graph[u]) {
        if(v != p) dfs(v, u, d + 1);
    }
}

void compute() {
    dfs(0, -1, 0);
    dfs(m, -1, 0);
    dfs(m, -1, 0);
}