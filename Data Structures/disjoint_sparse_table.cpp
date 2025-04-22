//queries 0-indexed
//valores iniciais em arr[]

int n2, table[2 * MAX][LOG];

void build() {
    n2 = n;
    while(n2 & (n2 - 1)) n2++;
    for(int j = 0; (1 << j) < n2; j++) {
        int len = 1 << j;
        for(int k = len; k < n2; k += 2 * len) {
            table[k][j] = arr[k];
            table[k - 1][j] = arr[k - 1];
            for(int i = k + 1; i < k + len; i++) table[i][j] = table[i - 1][j] ^ arr[i];
            for(int i = k - 2; i >= k - len; i--) table[i][j] = arr[i] ^ table[i + 1][j];
        }
    }
}

int query(int l, int r) {
    if(l == r) return arr[l];
    int j = __builtin_clz(1) - __builtin_clz(l ^ r);
    return table[l][j] ^ table[r][j];
}