int sz, path[MAXG], graph[MAXG][MAXG], parent[MAXG][MAXG];

void floydWarshall() {
    for(int k = 0; k < n; k++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(graph[i][j] > graph[i][k] + graph[k][j]) {
                    graph[i][j] = graph[i][k] + graph[k][j];
                    parent[i][j] = parent[k][j];
                }
            }
        }
    }
}
 
void recover(int u, int v) {
    while(u != v) {
        path[sz++] = v;
        v = parent[u][v];
    }
    path[sz++] = u;
}

void setEdge(int u, int v, int w) {
    graph[u][v] = w;
    graph[v][u] = w;
    parent[u][v] = u;
    parent[v][u] = v;
}
