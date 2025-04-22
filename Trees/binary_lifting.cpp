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