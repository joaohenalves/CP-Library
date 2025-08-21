// retorna 1 se o grafo dirigido contém ao menos um ciclo

int vis[MAX];

int dfs(int u) {
    vis[u] = 1;
    for(int &v : graph[u]) {
        if(vis[v] == 1) return 1;
        if(vis[v] == 0 && dfs(v)) return 1;
    }
    vis[u] = 2;
    return 0;
}

int findCycle() {
    for(int i = 0; i < n; i++) {
        if(vis[i] == 2) continue;
        if(dfs(i)) return 1;
    }
    return 0;
}