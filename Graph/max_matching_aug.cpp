// na variável n deve estar o tamanho do conjunto dos vértices
// da "esquerda" do grafo bipartido
// no m, o da direita
// vertices do lado esquerdo enumerados de 0 a n - 1 e do lado direito de n até n + m - 1
// as arestas do grafo são direcionadas, somente inserir arestas da esquerda para a direita
// se possível, preferir que o conjunto menor de vertices seja o da esquerda, pois assim executa menos operações
// complexidade: O(V * E)


int vis[MAX], match[MAX];

int dfs(int u) {
    vis[u] = 1;
    for(int v : graph[u]) {
        if(match[v] == -1 || (vis[match[v]] == 0 && dfs(match[v]) == 1)) {
            match[v] = u;
            return 1;
        }
    }
    return 0;
}

int aug() {
    fill(match, match + n + m, -1);
    int ans = 0;
    for(int u = 0; u < n; u++) {
        fill(vis, vis + n, 0);
        ans += dfs(u);
    }
    return ans;
}