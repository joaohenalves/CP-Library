// Teorema de Erdös-Gallai
// Diz se uma lista contendo graus de vértices de um grafo não dirigido
// pode de fato compor um grafo válido
// Retorno = 1 é válido, 0 = não válido
// Os graus devem estar em deg, 1-indexed

int deg[MAX], rng[MAX];
ll l[MAX];

int erdosGallai() {
    int x, flag;
    ll total = 0;
    for(int i = 1; i <= n; i++) {
        total += deg[i];
    }
    if((total & 1) == 0) {
        flag = 1;
        sort(deg + 1, deg + n + 1, greater<int>());
        l[0] = 0;
        for(int i = 1; i <= n; i++) {
            l[i] = deg[i] + l[i - 1];
        }
        l[n + 1] = l[n];
        x = n;
        for(int i = 1; i <= n; i++) {
            while(deg[x] < i) x--;
            rng[i] = max(x, i);
        }
        for(int k = 1; k <= n; k++) {
            ll y = (ll) (rng[k] - k) * k + l[n] - l[rng[k]];
            if(l[k] > (ll) k * (k - 1) + y) {
                flag = 0;
                break;
            }
        }
    } else flag = 0;
    return flag;
}