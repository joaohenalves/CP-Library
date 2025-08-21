// Valores iniciais devem estar em m1
// O resultado final vai estar em m2
// Algoritmo não muito bom, ocupa 2 * log(k) * ord² memória

vector<vector<ll>> m1(MAXG, vector<ll> (MAXG)), m2(MAXG, vector<ll> (MAXG));
 
void multmat(vector<vector<ll>> &a, vector<vector<ll>> &b, vector<vector<ll>> &c, int ord) {
    for(int i = 0; i < ord; i++) {
        for(int j = 0; j < ord; j++) {
            c[i][j] = 0;
            for(int k = 0; k < ord; k++) {
                c[i][j] += (a[i][k] * b[k][j]) % MOD;
                c[i][j] %= MOD;
            }
        }
    }
}
 
void ident(vector<vector<ll>> &a, int ord) {
    for(int i = 0; i < ord; i++) {
        for(int j = 0; j < ord; j++) {
            a[i][j] = i == j;
        }
    }
}
 
void expbin(vector<vector<ll>> &a, vector<vector<ll>> &b, ll k, int ord) {
    vector<vector<ll>> c(MAXG, vector<ll> (MAXG));
    if(k < 0) return;
    if(k == 0) ident(b, ord);
    else if(k & 1) {
        expbin(a, c, k - 1, ord);
        multmat(a, c, b, ord);
    } else {
        expbin(a, c, k >> 1, ord);
        multmat(c, c, b, ord);
    }
}