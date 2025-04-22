int ord, counter, vis[MAX], scc[MAX], cycle[MAX], inStack[MAX];
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
    for(int u = 0; u < n; u++) {
        if(vis[u] == 0) tarjan(u);
    }
}