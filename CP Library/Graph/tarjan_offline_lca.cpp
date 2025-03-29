int nodeRank[MAX], ancestor[MAX], vis[MAX], ans[MAX];
vector<vector<pii>> queries(MAX);

int findSet(int u) {
    if(ancestor[u] == u) return u;
    return ancestor[u] = findSet(ancestor[u]);
}

void unionSets(int u, int v) {
    u = findSet(u);
    v = findSet(v);
    if(nodeRank[u] > nodeRank[v]) {
        ancestor[v] = u;
    } else {
        ancestor[u] = v;
        if(nodeRank[v] == nodeRank[u]) nodeRank[v]++;
    }
}

void dfs(int u) {
    vis[u] = 1;
    ancestor[u] = u;
    for(int v : graph[u]) {
        if(vis[v] == 0) {
            dfs(v);
            unionSets(u, v);
            ancestor[findSet(u)] = u;
            ancestor[u] = u;
        }
    }
    for(auto [v, i] : queries[u]) {
        if(vis[v] == 1) {
            ans[i] = ancestor[findSet(v)];
        }
    }
}

void processQueries(int q) {
    for(int i = 0; i < q; i++) {
        cin >> u >> v;
        u--; v--;
        queries[u].emplace_back(v, i);
        queries[v].emplace_back(u, i);
    }
    dfs(0); //vertice raiz da arvore
}

void clean() {
    fill(vis, vis + n, 0);
    fill(nodeRank, nodeRank + n, 0);
    for(int i = 0; i < n; i++) queries[i].clear();
}