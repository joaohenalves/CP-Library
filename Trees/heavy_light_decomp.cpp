// Processa de forma eficiente operações dinâmicas e queries entre todos
// os vértices de um caminho entre quaiquer vértices u e v

#define left(u) (2 * (u))
#define right(u) (left(u) + 1)

int cur_pos, st[2 * MAX], parent[MAX], depth[MAX], heavy[MAX], head[MAX], pos[MAX], aux[MAX];

int op(int a, int b) {
    return max(a, b);
}

void build_st() {
    for(int i = 0; i < n; i++) st[i + n] = aux[i];
    for(int i = n - 1; i > 0; i--) {
        st[i] = op(st[left(i)], st[right(i)]);
    }
}

int query_st(int l, int r) {
    int ans = 0;
    for(l += n, r += n; l <= r; ++l /= 2, --r /= 2) {
        if(l % 2 == 1) ans = op(ans, st[l]);
        if(r % 2 == 0) ans = op(ans, st[r]);
    }
    return ans;
}

void update_st(int u, int x) {
    u = pos[u];
    st[u += n] = x;
    while(u /= 2) st[u] = op(st[left(u)], st[right(u)]);
}

int dfs(int u) {
    int sz = 1, v_sz, max_v_sz = 0;
    for(int &v : graph[u]) {
        if(v != parent[u]) {
            parent[v] = u;
            depth[v] = depth[u] + 1;
            v_sz = dfs(v);
            sz += v_sz;
            if(v_sz > max_v_sz) {
                max_v_sz = v_sz;
                heavy[u] = v;
            }
        }
    }
    return sz;
}

void decompose(int u, int h) {
    head[u] = h;
    pos[u] = cur_pos++;
    if(heavy[u] != -1) decompose(heavy[u], h);
    for(int &v : graph[u]) {
        if(v != parent[u] && v != heavy[u]) {
            decompose(v, v);
        }
    }
}

void init() {
    memset(heavy, -1, sizeof(heavy));
    cur_pos = 0;
    dfs(0);
    decompose(0, 0);
    for(int i = 0; i < n; i++) {
        aux[pos[i]] = arr[i];
    }
    build_st();
}

int query(int u, int v) {
    int ans = 0;
    while(head[u] != head[v]) {
        if(depth[head[u]] > depth[head[v]]) swap(u, v);
        ans = op(ans, query_st(pos[head[v]], pos[v]));
        v = parent[head[v]];
    }
    if(depth[u] > depth[v]) swap(u, v);
    ans = op(ans, query_st(pos[u], pos[v]));
    return ans;
}

// Corretude do algoritmo verificada com os problemas:
// https://cses.fi/problemset/task/2134/