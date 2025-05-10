// Resolvedor de 2-SAT, retorno 1 = há solução, 0 = não há
// Resposta para o valor lógico de cada variável estará em ans

// A XOR B = (A ^ B) = (A | B) & (-A | -B) // colocar as 4 arestas para as duas disjunções
// Uma cláusula A XOR B significa uma obrigatoriedade de A e B serem diferentes

// A <-> B = (-A ^ B)
// A <-> B = (A -> B) & (-A -> -B)
// Uma cláusula A <-> B (A se e somente se B) significa uma obrigatoriedade de A e B serem iguais

#define pos(x) (2 * (x))
#define neg(x) (2 * (x) + 1)
 
int ord, idx, counter, vis[2 * MAX], inStack[2 * MAX], cycle[2 * MAX], scc[2 * MAX];
bool ans[MAX];
stack<int> stk;

void tarjan(int u) {
    vis[u] = cycle[u] = ord++;
    stk.push(u);
    inStack[u] = 1;
    for(int &v : graph[u]) {
        if(vis[v] == 0) tarjan(v);
        if(inStack[v]) cycle[u] = min(cycle[u], cycle[v]);
    }
    if(vis[u] == cycle[u]) {
        int w;
        do {
            w = stk.top();
            stk.pop();
            scc[w] = counter;
            inStack[w] = 0;
        } while(w != u);
        counter++;
    }
}
 
void initTarjan() {
    ord = 1;
    counter = 0;
    memset(vis, 0, sizeof(vis));
    memset(inStack, 0, sizeof(inStack));
    for(int u = 0; u < 2 * n; u++) {
        if(vis[u] == 0) tarjan(u);
    }
}
 
void setClause(int u, int v, int b1, int b2) {
    int u1, u2, v1, v2;
    u1 = neg(u);
    u2 = pos(u);
    v1 = neg(v);
    v2 = pos(v);
    if(b1 == 0) swap(u1, u2);
    if(b2 == 0) swap(v1, v2);
    graph[u1].push_back(v2);
    graph[v1].push_back(u2);
}

int twoSat() {
    initTarjan();
    for(int i = 0; i < 2 * n; i += 2) {
        if(scc[i] == scc[i + 1]) {
            return 0;
        } else {
            if(scc[i] < scc[i + 1]) ans[i / 2] = 1;
            else ans[i / 2] = 0;
        }
    }
    return 1;
}
