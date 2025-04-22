// na variável n deve estar o tamanho do conjunto dos vértices
// da "esquerda" do grafo bipartido

// as arestas do grafo são direcionadas, somente inserir arestas da esquerda para a direita

int match[MAX], vis[MAX], dist[MAX];

int dfs(int u) {
    int w;
    vis[u] = 1;
    for(int &v : graph[u]) {
        w = match[v];
        if(w == -1 || (dist[w] == dist[u] + 1 && vis[w] == 0 && dfs(w))) {
            match[v] = u;
            match[u] = v;
            return 1;
        }
    }
    return 0;
}

int bfs() {
    int u, w, i;
    queue<int> q;
    for(u = 0; u < n; u++) {
        if(match[u] == -1) {
            dist[u] = 0;
            q.push(u);
        } else dist[u] = INF;
    }
    while(!q.empty()) {
        u = q.front();
        q.pop();
        for(int &v : graph[u]) {
            w = match[v];
            if(w == -1) return 1;
            if(dist[w] == INF) {
                dist[w] = dist[u] + 1;
                q.push(w);
            }
        }
    }
    return 0;
}

int hopcroftKarp() {
    int u, ans = 0;
    memset(match, -1, sizeof(match));
    while(bfs()) {
        memset(vis, 0, sizeof(vis));
        for(u = 0; u < n; u++) {
            if(match[u] == -1 && vis[u] == 0) ans += dfs(u);
        }
    }
    return ans;
}