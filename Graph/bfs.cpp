int dist[MAX], parent[MAX];

void bfs(int s) {
    queue<int> q;
    fill(dist, dist + n, INF);
    dist[s] = 0;
    parent[s] = -1;
    q.push(s);
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for(int &v : graph[u]) {
            if(dist[v] == INF) {
                dist[v] = dist[u] + 1;
                parent[v] = u;
                q.push(v);
            }
        }
    }
}
