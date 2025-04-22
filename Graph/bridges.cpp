int ans, timer, vis[MAX], tin[MAX], low[MAX];

void dfs(int u, int p) {
    vis[u] = 1;
    tin[u] = low[u] = timer++;
    for(int v : graph[u]) {
        if(v != p) {
            if (vis[v]) {
                low[u] = min(low[u], tin[v]);
            } else {
                dfs(v, u);
                low[u] = min(low[u], low[v]);
                if(low[v] > tin[u]) {
                    // Aresta (u <-> v) é uma ponte, processe-a aqui
                }
            }
        }
    }
}

void findBridges() {
    timer = ans = 0;
    memset(vis, 0, sizeof(vis));
    memset(tin, -1, sizeof(tin));
    memset(low, -1, sizeof(low));
    for(int i = 0; i < n; i++) {
        if(vis[i] == 0) dfs(i, -1);
    }
}