// valores iniciais em arr
// tudo 0-indexed
// BSIZE é raiz quadrada de MAX
// query em O(sqrt(n)), update em O(1)
// caso haja um fator log envolvido na resposta das queries, o BSIZE ótimo é sqrt(n / log(n))

#define BSIZE 450
ll block[BSIZE];

void preprocess() {
    for(int i = 0; i < n; i++) {
        block[i / BSIZE] += arr[i];
    }
}

ll query(int l, int r) {
    int bl = l / BSIZE, br = r / BSIZE;
    ll ans = 0;
    if(bl == br) {
        for(int i = l; i <= r; i++) ans += arr[i];
    } else {
        for(int i = l; i < (bl + 1) * BSIZE; i++) ans += arr[i];
        for(int i = bl + 1; i < br; i++) ans += block[i];
        for(int i = br * BSIZE; i <= r; i++) ans += arr[i];
    }
    return ans;
}

void update(int i, ll x) {
    int b = i / BSIZE;
    block[b] += x - arr[i];
    arr[i] = x;
}