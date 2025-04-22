// constrói o grafo de condensação dos componentes fortemente conectados
// o grafo resultante será um DAG (directed acyclic graph)

// deve ser utilizado após rodar o algoritmo de Tarjan

vector<set<int>> dag(MAX);

void setDag() {
    for(int u = 0; u < n; u++) {
        for(int &v : graph[u]) {
            if(scc[u] != scc[v]) {
                dag[scc[u]].insert(scc[v]);
            }
        }
    }
}