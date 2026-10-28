int pi, lp[MAX], pr[MAX];

void linearSieve() {
    pi = 0;
    for(int i = 2; i < MAX; i++) {
        if(lp[i] == 0) {
            lp[i] = i;
            pr[pi++] = i;
        }
        for(int j = 0; i * pr[j] < MAX; j++) {
            lp[i * pr[j]] = pr[j];
            if(pr[j] == lp[i]) break;
        }
    }
}

// retorna o vetor só com os primos
vector<int> factorize(int x) {
    vector<int> factors;
    while(x > 1) {
        if(factors.empty() || factors.back() != lp[x]) {
            factors.push_back(lp[x]);
        }
            x /= lp[x];
        }
    return factors;
}

// retorna o vetor com os primos e o expoente
// (não testado)
vector<pii> factorize(int x){
    vector<pii> factors;
    while(x > 1) {
        if(factors.empty() || factors.back().first != lp[x]) {
            factors.emplace_back(lp[x], 0);
        }
        x /= lp[x];
        factors.back().second++;
    }
    return factors;
}