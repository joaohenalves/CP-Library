// retorno 1 significa ciclo de peso negativo

int dist[MAX];

int bellmanFord(int src) {
    int flag = 0;
    for(int i = 0; i < n; i++) dist[i] = INF;
    dist[src] = 0;
    for(int i = 0; i < n; i++) {
        flag = 0;
        for(int u = 0; u < n; u++) {
            for(auto &[v, dv] : graph[u]) {
                if(dist[u] != INF && dist[v] > dist[u] + dv) {
                    dist[v] = dist[u] + dv;
                    flag = 1;
                }
            }
        }
    }
    return flag;
}