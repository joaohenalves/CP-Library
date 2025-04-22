ll w[MAX][MAX], mat[MAX][MAX], pi[MAX], pj[MAX], p[MAX], way[MAX], ans[MAX];
//pi e ans = n + 1, o resto m + 1;

//É possível transformar o problema de minimização em um de maximização,
//basta multiplicar todos os valores de mat[][] por -1 e printar -hungarian()
//TUDO ESTÁ INDEXADO EM 1!!!!

ll hungarian() {
    for(int i = 1; i <= n; i++) {
        p[0] = i;
        int j0 = 0;
        vector<ll> minv(m + 1, INFLL);
        vector<bool> used(m + 1, false);
        do {
            used[j0] = true;
            ll i0 = p[j0], delta = INFLL, j1;
            for(int j = 1; j <= m; j++) {
                if(!used[j]) {
                    ll cur = mat[i0][j] - pi[i0] - pj[j];
                    if(cur < minv[j]) minv[j] = cur, way[j] = j0;
                    if(minv[j] < delta) delta = minv[j], j1 = j;
                }
            }
            for(int j = 0; j <= m; j++) {
                if(used[j]) pi[p[j]] += delta, pj[j] -= delta;
                else minv[j] -= delta;
            }
            j0 = j1;
        } while(p[j0] != 0);
        do {
            int j1 = way[j0];
            p[j0] = p[j1];
            j0 = j1;
        } while(j0);
    }
    for(int j = 1; j <= m; j++) ans[p[j]] = j; //recupera a resposta
    return -pj[0];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int u, v;
    ll cost;
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> w[i][j];
        }
    }
    for(int i = 0; i < n; i += 2) {
        for(int j = 0; j < n; j += 2) {
            mat[i / 2 + 1][j / 2 + 1] = (j - 1 >= 0 ? w[j - 1][i] : 0) + (j + 1 < n ? w[i][j + 1] : 0);
        }
    }
    n = (n + 1) / 2;
    m = n;
    cout << hungarian() << '\n';
    return 0;
}