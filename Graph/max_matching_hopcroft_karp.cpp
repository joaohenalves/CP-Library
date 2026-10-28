// na variável n deve estar o tamanho do conjunto dos vértices
// da "esquerda" do grafo bipartido
// no m, o da direita
// vertices do lado esquerdo enumerados de 0 a n - 1 e do lado direito de n até n + m - 1
// as arestas do grafo são direcionadas, somente inserir arestas da esquerda para a direita
// complexidade: O(sqrt(V) * E)

int match[MAX], vis[MAX], dist[MAX];

int dfs(int u) {
    vis[u] = 1;
    for(int v : graph[u]) {
        if(match[v] == -1 || (dist[match[v]] == dist[u] + 1 && vis[match[v]] == 0 && dfs(match[v]))) {
            match[v] = u;
            match[u] = v;
            return 1;
        }
    }
    return 0;
}

int bfs() {
    int u;
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
        for(int v : graph[u]) {
            if(match[v] == -1) return 1;
            if(dist[match[v]] == INF) {
                dist[match[v]] = dist[u] + 1;
                q.push(match[v]);
            }
        }
    }
    return 0;
}

int hopcroftKarp() {
    int ans = 0;
    fill(match, match + n + m, -1);
    while(bfs()) {
        fill(vis, vis + n, 0);
        for(int u = 0; u < n; u++) {
            if(match[u] == -1 && vis[u] == 0) ans += dfs(u);
        }
    }
    return ans;
}