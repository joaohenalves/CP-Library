// Faz update de soma em todos os vértices no caminho
// entre um par de vértices u e v qualquer
// Estático, todos os updates devem acontecer antes de qualquer consulta

// ATENÇÃO, A RAIZ DA ÁRVORE DEVE SER UM VÉRTICE 0 EXTRA, se a árvore já contém
// outra raiz 1, por exemplo, 1 deve ser pendurado em baixo de 0.
// isso significa que a indexação dos vértices deve ser 1-indexed

// LANÇAR dfs(0, 0) APÓS OS UPDATES, então sum[u] para qualquer u conterá sua soma final

int depth[MAX], up[MAX][LOG], diff[MAX], sum[MAX];

void dfs(int u, int p, int d) {
    up[u][0] = p;
    depth[u] = d;
    for(int i = 1; i < LOG; i++) {
        up[u][i] = up[up[u][i - 1]][i - 1];
    }
    for(int &v : graph[u]) {
        if(v != p) dfs(v, u, d + 1);
    }
}

int findKthAncestor(int u, int k) {
    if(k > depth[u]) return -1;
    for(int i = 0; i < LOG; i++) {
        if(k & (1 << i)) {
            u = up[u][i];
        }
    }
    return u;
}

int lca(int u, int v) {
    if(depth[u] > depth[v]) swap(u, v);
    v = findKthAncestor(v, depth[v] - depth[u]);
    for(int i = LOG - 1; i >= 0; i--) {
        if(up[u][i] != up[v][i]) {
            u = up[u][i];
            v = up[v][i];
        }
    }
    return u != v ? up[u][0] : u;
}

int dfs(int u, int p) {
    sum[u] = diff[u];
    for(int &v : graph[u]) {
        if(v != p) {
            sum[u] += dfs(v, u);
        }
    }
    return sum[u];
}

void preprocess() {
    // 1 ou qualquer outro vértice é a raiz original da árvore
    graph[0].push_back(1);
    graph[1].push_back(0);
    dfs(0, 0, 0);
}

void update(int u, int v, int delta) {
    int l = lca(u, v);
    diff[u] += delta;
    diff[v] += delta;
    diff[l] -= delta;
    diff[up[l][0]] -= delta;
}
