// Algoritmo de Mo para responder queries difíceis sobre segmentos delimitados por l e r arbitrários
// tudo 0-indexed
// k deve conter a quantidade de queries
// inserir no vetor queries do como (l, r, i), l e r os limites e i o índice da query
// resposta para cada query na ordem da entrada estará em ans
// modificar a estrutura e lógica de add/remove para o que o problema pedir
// BSIZE = sqrt(MAX)

// no exemplo abaixo, o algoritmo é utilizado para responder as seguintes queries:
// dado um subarray delimitado por l e r, responder quantos números distintos existem nesse intervalo

int ans[MAX], occ[MAX];
const int BSIZE = 450;
vector<tiii> queries(MAX);

bool comp(const tiii a, const tiii b) {
    auto [al, ar, ai] = a;
    auto [bl, br, bi] = b;
    if(al / BSIZE != bl / BSIZE) return a < b;
    return (al / BSIZE & 1) ? (ar < br) : (ar > br);
}

void remove(int i) {
    occ[arr[i]]--;
    if(occ[arr[i]] == 0) m--;
}

void add(int i) {
    occ[arr[i]]++;
    if(occ[arr[i]] == 1) m++;
}

int getAns() {
    return m;
}

void mo() {
    sort(queries.begin(), queries.begin() + k, comp);
    int l = 0, r = -1;
    for(int i = 0; i < k; i++) {
        auto &[ql, qr, j] = queries[i];
        while(l > ql) {
            l--;
            add(l);
        }
        while(r < qr) {
            r++;
            add(r);
        }
        while(l < ql) {
            remove(l);
            l++;
        }
        while(r > qr) {
            remove(r);
            r--;
        }
        ans[j] = getAns();
    }
}