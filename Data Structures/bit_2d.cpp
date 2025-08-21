// tudo 1-indexed

ll bit[MAXG][MAXG];

void setbit(int x, int y, int delta) {
    for(int i = x; i <= n; i += i & -i) {
        for(int j = y; j <= m; j += j & -j) {
            bit[i][j] += delta;
        }
    }
}


ll getbit(int x, int y) {
    ll ans = 0;
    for(int i = x; i > 0; i -= i & -i) {
        for(int j = y; j > 0; j -= j & -j) {
            ans += bit[i][j];
        }
    }
    return ans;
}

ll rectangle(int i1, int j1, int i2, int j2) {
    if(i2 > i1) swap(i1, i2);
    if(j2 > j1) swap(j1, j2);
    return getbit(i1, j1) - getbit(i1, j2 - 1) - getbit(i2 - 1, j1) + getbit(i2 - 1, j2 - 1);
}