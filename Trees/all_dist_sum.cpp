// array ans contém para cada vértice, a soma de todas as distancias
// para os outros vértices

ll tsize[MAX], dist[MAX], prop[MAX], ans[MAX];

void dfs1(int u, int p) {
    ll a = 0;
    tsize[u] = 0;
    for(int &v : graph[u]) {
        if(v != p) {
            dfs1(v, u);
            a += prop[v];
            tsize[u] += 1 + tsize[v];
        }
    }
    dist[u] = a;
    prop[u] = a + tsize[u] + 1;
}
 
void dfs2(int u, int p) {
    if(u != 0) ans[u] = dist[u] + ans[p] - prop[u] + (n - tsize[u] - 1);
    for(int &v : graph[u]) {
        if(v != p) {
            dfs2(v, u);
        }
    }
}

void compute() {
    dfs1(0, 0);
    ans[0] = dist[0];
    dfs2(0, 0);
}