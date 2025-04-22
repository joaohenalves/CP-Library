// Calcula do lowest common ancestor de dois vértices com binary lifting
// dfs deve ser chamada com dfs(raiz, raiz, 0)

int depth[MAX], up[MAX][LOG];
 
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