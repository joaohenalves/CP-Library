// graph deve ser modificado para vector<vector<pii>> graph(MAX);
// Vértice inicial 's', que não possui pai na busca
// Colocar retorno de distancia caso haja um vértice específico para o qual queremos saber a distância
// caso contrário, deixar como está, e dist conterá a distância para todos os vértices a partir de 's'

int dist[MAX], parent[MAX];

void dijkstra(int s) {
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    fill(dist, dist + n, INF);
    fill(parent, parent + n, -1);
    dist[s] = 0;
    pq.emplace(0, s);
    while(!pq.empty()) {
        auto [du, u] = pq.top();
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
