//queries 0-indexed
//valores iniciais em arr[]

int table[MAX][LOG];

void build() {
    for(int i = 0; i < n; i++) table[i][0] = arr[i];
    for(int j = 1; j < LOG; j++) {
        for(int i = 0; i + (1 << j) - 1 < n; i++) {
            table[i][j] = min(table[i][j - 1], table[i + (1 << (j - 1))][j - 1]);
        }
    }
}

int query(int l, int r) {
    int j = __builtin_clz(1) - __builtin_clz(r - l + 1);
    return min(table[l][j], table[r - (1 << j) + 1][j]);
}