// Constrói o euler tour da árvore
// A sub árvore enraizada em qualquer nodo u vai estar em um subarray
// delimitado por [tin[u], tout[u]]
// inicializar timer em 1 caso for utilizar bit para queries nos subarrays
// deixar 0 caso usar segtree

int timer, tin[MAX], tout[MAX];

void dfs(int u, int p) {
    tin[u] = timer++;
    for(int &v : graph[u]) {
        if(v != p) dfs(v, u);
    }
    tout[u] = timer - 1;
}