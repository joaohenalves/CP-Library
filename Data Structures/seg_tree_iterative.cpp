// Operações 0-indexed

#define left(u) (2 * (u))
#define right(u) (left(u) + 1)

int st[2 * MAX];

void build() {
    for(int i = n - 1; i > 0; i--) {
        st[i] = st[left(i)] + st[right(i)];
    }
}

int query(int l, int r) {
    int ans = 0;
    for(l += n, r += n; l <= r; ++l /= 2, --r /= 2) {
        if(l % 2 == 1) ans += st[l];
        if(r % 2 == 0) ans += st[r];
    }
    return ans;
}

void update(int u, int x) {
    st[u += n] = x;
    while(u /= 2) st[u] = st[left(u)] + st[right(u)];
}