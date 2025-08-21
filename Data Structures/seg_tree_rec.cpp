#define left(u) ((u) + 1)
#define right(u, m, l) ((u) + 2 * ((m) - (l) + 1))
 
ll st[2 * MAX];
 
ll build_st(int u, int l, int r) {
    int m = (l + r) / 2;
    if(l == r) return st[u] = arr[l];
    return st[u] = build_st(left(u), l, m) + build_st(right(u, m, l), m + 1, r);
}
 
ll query_st(int u, int l, int r, int i, int j) {
    if(r < i || l > j) return 0;
    if(i <= l && r <= j) return st[u];
    int m = (l + r) / 2;
    return query_st(left(u), l, m, i, j) + query_st(right(u, m, l), m + 1, r, i, j);
}
 
ll update_st(int u, int l, int r, int i, ll val) {
    if(i < l || i > r) return st[u];
    if(i == l && l == r) return st[u] = val;
    int m = (l + r) / 2;
    return st[u] = update_st(left(u), l, m, i, val) + update_st(right(u, m, l), m + 1, r, i, val);
}

//Tudo 0-indexed
build_st(0, 0, n - 1);
update_st(0, 0, n - 1, i, j);
query_st(0, 0, n - 1, i, j)