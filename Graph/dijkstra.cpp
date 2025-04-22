int dist[MAX], parent[MAX];

void dijkstra(int s) {
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    fill(dist, dist + n, INF);
    dist[s] = 0;
    parent[s] = -1;
    pq.emplace(0, s);
    while(!pq.empty()) {
        auto [u, du] = pq.top();
        pq.pop();
        if(du > dist[u]) continue;
        for(auto &[v, dv] : graph[u]) {
            if(dist[v] > du + dv) {
                dist[v] = du + dv;
                parent[v] = u;
                pq.emplace(du + dv, v);
            }
        }
    }
}