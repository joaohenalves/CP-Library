//Atenção: se a lista de nxt é uma permutação, o grafo conterá apenas ciclos!
//não haverão vértices de fora que levam a um ciclo. isso facilita muito
//o processamento do grafo

int nxt[MAX], comp[MAX], cyc[MAX], pos[MAX], dist[MAX], vis[MAX], up[MAX][LOG];

void dfs(int u, int c) {
    vis[u] = 1;
    comp[u] = c;
    for(int &v : graph[u]) {
        if(vis[v] == 0) dfs(v, c);
    }
}

void binaryLifting() {
    for(int i = 0; i < n; i++) {
        up[i][0] = nxt[i];
    }
    for(int i = 1; i < LOG; i++) {
        for(int j = 0; j < n; j++) {
            up[j][i] = up[up[j][i - 1]][i - 1];
        }
    }
}

void findCycles(int u) {
    vis[u] = 1;
    if(vis[nxt[u]] == 1) {
        if(cyc[nxt[u]] == -1) {
            int v = u;
            int p = 0;
            do {
                pos[v] = p++;
                dist[v] = 0;
                v = nxt[v];
            } while(v != u);
            do {
                cyc[v] = p;
                v = nxt[v];
            } while(v != u);
        } else {
            dist[u] = dist[nxt[u]] + 1;
            cyc[u] = 0;
        }
    } else {
        findCycles(nxt[u]);
        if(cyc[u] == -1) {
            dist[u] = dist[nxt[u]] + 1;
            cyc[u] = 0;
        }
    }
}

int getCycleDist(int u, int v) {
    int a = pos[u], b = pos[v];
    if(b < a) swap(a, b);
    return min(b - a, cyc[u] - b + a);
}

int minDistMeetingVertex(int u, int v) {
    int a, b, d, ans;
    if(comp[u] != comp[v]) ans = -1;
    else if(u == v) ans = 0;
    else {
        if(cyc[v] != 0) swap(u, v);
        if(cyc[u] != 0 && cyc[v] != 0) {
            ans = getCycleDist(u, v);
        } else if(cyc[u] != 0 && cyc[v] == 0) {
            d = dist[v];
            for(int i = 0; i < LOG; i++) {
            if(d & (1 << i)) v = up[v][i];
            }
            ans = d;
            if(u != v) {
                ans += getCycleDist(u, v);
            }
        } else {
            if(dist[v] < dist[u]) swap(u, v);
            a = dist[v] - dist[u];
            for(int i = 0; i < LOG; i++) {
                if(a & (1 << i)) {
                    v = up[v][i];
                }
            }
            ans = a;
            if(u != v) {
                b = dist[u];
                ans += 2 * b;
                int u1 = u, v1 = v;
                for(int i = LOG - 1; i >= 0; i--) {
                    if(b & (1 << i)) {
                        u1 = up[u1][i];
                        v1 = up[v1][i];
                    }
                }
                if(u1 == v1) {
                    for(int i = LOG - 1; i >= 0; i--) {
                        if(up[u][i] != up[v][i]) {
                            u = up[u][i];
                            v = up[v][i];
                        }
                    }
                    u = nxt[u];
                    v = nxt[v];
                    ans -= 2 * dist[u];
                } else {
                    ans += getCycleDist(u1, v1);
                }
            }
        }
    }
    return ans;
}

void readAndProcess() {
    int u, c = 0;
    for(int i = 0; i < n; i++) {
        cin >> u;
        u--;
        nxt[i] = u;
        graph[i].push_back(u);
        graph[u].push_back(i);
    }
    fill(vis, vis + n, 0);
    for(int i = 0; i < n; i++) {
        if(vis[i] == 0) {
            dfs(i, c);
            c++;
        }
    }
    fill(cyc, cyc + n, -1);
    fill(vis, vis + n, 0);
    for(int i = 0; i < n; i++) {
        if(vis[i] == 0) findCycles(i);
    }
    binaryLifting();
}
