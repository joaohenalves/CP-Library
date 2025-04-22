// query retorna para um dado x, quantos números estritamente maiores que x
// existem no prefixo
// é preciso ordenar cada nó da bit antes de usar!

vector<vector<int>> bit(MAX);

void insertBit(int i, int x) {
    while(i <= n) {
        bit[i].push_back(x);
        i += i & -i;
    }
}

int query(int i, int x) {
    int ans = 0;
    while(i) {
        ans += bit[i].end() - upper_bound(bit[i].begin(), bit[i].end(), x);
        i -= i & -i;
    }
    return ans;
}