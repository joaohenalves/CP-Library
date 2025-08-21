// Ford-Fulkerson-Edmonds-Karp
// O(V * E²)

int parent[MAX], dist[MAX], cap[MAX][MAX];
 
int bfs(int s, int t) {
    int u, bneck = INF;
    queue<int> q;
    for(u = 0; u < n; u++) dist[u] = INF;
    dist[s] = 0;
    q.push(s);
    while(!q.empty()) {
        u = q.front();
        q.pop();
        if(u == t) break;
        for(int &v : graph[u]) {
            if(cap[u][v] > 0 && dist[v] == INF) {
                dist[v] = dist[u] + 1;
                parent[v] = u;
                q.push(v);
            }
        }
    }
    if(dist[t] == INF) return 0;
    for(u = t; u != s; u = parent[u]) {
        bneck = bneck > cap[parent[u]][u] ? cap[parent[u]][u] : bneck;
    }
    return bneck;
}
 
int ffek(int s, int t) {
    int u, bneck, f = 0;
    while((bneck = bfs(s, t))) {
        for(u = t; u != s; u = parent[u]) {
            cap[parent[u]][u] -= bneck;
            cap[u][parent[u]] += bneck;
        }
        f += bneck;
    }
    return f;
}

void setEdge(int u, int v, int w) {
    if(cap[u][v] == 0) {
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    cap[u][v] += w;
    // se a aresta for bidirecional, adicionar w ao cap[v][u] também
}