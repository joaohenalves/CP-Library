#define left(u) ((u) + 1)
#define right(u, m, l) ((u) + 2 * ((m) - (l) + 1))

int st[2 * MAX], lazy[2 * MAX];

void update_lazy(int u, int l, int r, int val) {
    int m = (l + r) / 2;
    int k = r - l + 1;
    st[u] += k * val;
    if(l < r) {
        lazy[left(u)] += val;
        lazy[right(u, m, l)] += val;
    }
    lazy[u] = 0;
}

int build_st(int u, int l, int r) {
    int m = (l + r) / 2;
    if(l == r) return st[u] = arr[l];
    return st[u] = build_st(left(u), l, m) + build_st(right(u, m, l), m + 1, r);
}
 
int query_st(int u, int l, int r, int i, int j) {
    if(lazy[u] < 0) update_lazy(u, l, r, lazy[u]);
    if(r < i || l > j) return 0;
    if(i <= l && r <= j) return st[u];
    int m = (l + r) / 2;
    return query_st(left(u), l, m, i, j) + query_st(right(u, m, l), m + 1, r, i, j);
}

int update_range(int u, int l, int r, int i, int j, int val) {
    if(lazy[u] < 0) update_lazy(u, l, r, lazy[u]);
    if(r < i || l > j) return st[u];
    if(i <= l && r <= j) {
        update_lazy(u, l, r, val);
        return st[u];
    }
    int m = (l + r) / 2;
    return st[u] = update_range(left(u), l, m, i, j, val) + update_range(right(u, m, l), m + 1, r, i, j, val);
}