//Tudo 1-indexed

ll bit[MAX];

void setbit(int i, ll delta) {
    while(i <= n) {
        bit[i] += delta;
        i += i & -i;
    }
}

ll getbit(int i) {
    ll ans = 0;
    while(i) {
        ans += bit[i];
        i -= i & -i;
    }
    return ans;
}

void build() {
    int j;
    for(int i = 1; i <= n; i++) {
        j = i + (i & -i);
        if(j <= n) bit[j] += bit[i];
    }
}

void setrange(int l, int r, ll delta) {
    setbit(l, delta);
    setbit(r + 1, -delta);
}
