void dfs(int u, int p) {
    for(int &v : graph[u]) {
        if(v != p) {
            arr[v] = arr[u] + 1;
            dfs(v, u);
        }
    }
}

int diameter() {
    int u = 0, v = 0;
    arr[0] = 0;
    dfs(0, 0);
    for(int i = 0; i < n; i++) {
        if(arr[i] > v) {
            v = arr[i];
            u = i;
        }
    }
    arr[u] = 0;
    dfs(u, u);
    return *max_element(arr, arr + n);
}