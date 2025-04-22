int idx, counter, tot, ans[MAX], degree[MAX], vis[MAX];
vector<unordered_set<int>> graph(MAX);
stack<int> stk;

void eulerTour() {
    int u, v;
    idx = 0;
    stk.push(0); // origem do tour
    while(!stk.empty()) {
        u = stk.top();
        if(graph[u].empty()) {
            ans[idx++] = u;
            stk.pop();
        } else {
            v = *(graph[u].begin());
            stk.push(v);
            graph[u].erase(v);
            graph[v].erase(u);
        }
    }
}

void dfs(int u) {
    vis[u] = 1;
    counter += graph[u].size();
    for(int v : graph[u]) {
        if(vis[v] == 0) dfs(v);
    }
}

bool isValid() {
    for(int i = 0; i < n; i++) {
        if(degree[i] & 1) return 0;
    }
    dfs(0);
    if(counter != tot) return 0;
    eulerTour();
    return 1;
}

void setEdge(int u, int v) {
    degree[u]++;
    degree[v]++;
    tot += 2;
    graph[u].insert(v);
    graph[v].insert(u);
}