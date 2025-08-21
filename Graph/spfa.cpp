// Shortest Path Faster Algorithm (Bellman-Ford que funciona melhorzinho na prática)
// Complexidade continua sendo O(v³)

// retorno 1 significa contém ciclo de peso negativo

int cnt[MAX], inQueue[MAX], dist[MAX];

int spfa() {
    fill(dist, dist + n, INFLL);
    queue<int> q;
    dist[0] = 0;
    inQueue[0] = 1;
    q.push(0);
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        inQueue[u] = 0;
        for(auto &[v, dv] : graph[u]) {
            if(dist[v] > dist[u] + dv) {
                dist[v] = dist[u] + dv;
                if(inQueue[v] == 0) {
                    q.push(v);
                    inQueue[v] = 1;
                    cnt[v]++;
                    if(cnt[v] > n) return 1;
                }
            }
        }
    }
    return 0;
}