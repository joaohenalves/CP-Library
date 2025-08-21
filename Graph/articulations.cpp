// Detecta os pontos de articulação do grafo não dirigido
// artic[u] = 1 significa que removendo o vértice u, aumenta-se o número de componentes conexos do grafo

int timer, vis[MAX], tin[MAX], low[MAX], artic[MAX];

void dfs(int u, int p) {
    vis[u] = 1;
    tin[u] = low[u] = timer++;
    for(int v : graph[u]) {
        if(v != p) {
            if(vis[v]) {
                low[u] = min(low[u], tin[v]);
            } else {
                dfs(v, u);
                low[u] = min(low[u], low[v]);
                if((p != -1 && low[v] >= tin[u]) ||
                    (p == -1 && low[v] > tin[u] && graph[u].size() > 1)) {
                    artic[u] = 1;
                }
            }
        }
    }
}

void findArticulations() {
    timer = 0;
    memset(vis, 0, sizeof(vis));
    memset(tin, -1, sizeof(tin));
    memset(low, -1, sizeof(low));
    memset(artic, 0, sizeof(artic));
    for(int i = 0; i < n; i++) {
        if(vis[i] == 0) dfs(i, -1);
    }
}