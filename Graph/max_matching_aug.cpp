// na variável n deve estar o tamanho do conjunto dos vértices
// da "esquerda" do grafo bipartido

// as arestas do grafo são direcionadas, somente inserir arestas da esquerda para a direita


int vis[MAX], match[MAX];

int dfs(int u) {
    vis[u] = 1;
    for(int &v : graph[u]) {
        if(match[v] == -1 || (vis[match[v]] == 0 && dfs(match[v]))) {
            match[v] = u;
            return 1;
        }
    }
    return 0;
}

int aug() {
    memset(match, -1, sizeof(match));
    int ans = 0;
    for(int u = 0; u < n; u++) {
        memset(vis, 0, sizeof(vis));
        if(vis[u] == 0) ans += dfs(u);
    }
    return ans;
}