int vis[MAX];

int prim(int s) {
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    int ans = 0, t = 0;
    pq.emplace(0, s);
    while(!pq.empty()) {
        auto [du, u] = pq.top();
        pq.pop();
        if(vis[u]) continue;
        vis[u] = 1;
        t++;
        ans += du;
        for(auto &[v, dv] : graph[u]) {
            if(vis[v] == 0) pq.emplace(dv, v);
        }
    }
    return t == n ? ans : -1;
}