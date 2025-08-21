// Valores iniciais e resultado fica em m1
// Não ocupa muita memória extra

vector<vector<ll>> m1(MAXG, vector<ll> (MAXG)), m2(MAXG, vector<ll> (MAXG));
 
void multmat(vector<vector<ll>> &a, vector<vector<ll>> &b, int ord) {
    vector<vector<ll>> c(MAXG, vector<ll> (MAXG));
    for(int i = 0; i < ord; i++) {
        for(int j = 0; j < ord; j++) {
            for(int k = 0; k < ord; k++) {
                c[i][j] += (a[i][k] * b[k][j]) % MOD;
                c[i][j] %= MOD;
            }
        }
    }
    a = c;
}
 
void ident(vector<vector<ll>> &a, int ord) {
    for(int i = 0; i < ord; i++) {
        for(int j = 0; j < ord; j++) {
            a[i][j] = i == j;
        }
    }
}
 
void expbinmat(int k, int ord) {
    ident(m2, ord);
    while(k) {
        if(k & 1) {
            multmat(m2, m1, ord);
        }
        multmat(m1, m1, ord);
        k >>= 1;
    }
    m1 = m2;
}