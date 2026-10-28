//vet é um vetor de frequências dos números
//n deve ser igual ao maior numero do vet + 1
//complexidade O(n log n)
//maior número intermediário computado: (qtd total de numeros)^2
void gcdSelfConvolution() {
    for(int i = 1; i <= n; i++) {
        for(int j = i + i; j <= n; j += i) {
            vet[i] += vet[j];
        }
        vet[i] = vet[i] * (vet[i] - 1LL) / 2LL;
    }
    for(int i = n; i >= 1; i--) {
        for(int j = i + i; j <= n; j += i) {
            vet[i] -= vet[j];
        }
    }
}

vector<ll> gcdConvolution(vector<ll> &a, vector<ll> &b) {
    vector<ll> ans(n + 1);
    for(int i = 1; i <= n; i++) {
        ll ca = 0LL, cb = 0LL;
        for(int j = i; j <= n; j += i) {
            ca += a[j];
            cb += b[j];
        }
        ans[i] = ca * cb;
    }
    for(int i = n; i >= 1; i--) {
        for(int j = i + i; j <= n; j += i) {
            ans[i] -= ans[j];
        }
    }
    return ans;
}


//cuidado com o subset vazio, se faz sentido ter ou pegar algo dele
//cuidado com overflow
//n = quantidade maxima de bits
// fa, fb = resultado do sos dp para arrays iniciais sa e sb
//dp = resultado final da convolução
int dp[MAX], fa[MAX], fb[MAX], sa[MAX], sb[MAX];

void sos_dp(int f[], int s[]) {
    for(int i = 0; i < (1 << n); i++) {
        f[i] = s[i]; // resposta para o subset individual de mascara i
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < (1 << n); j++){
            if(j & (1 << i)) {
                f[j] += f[j ^ (1 << i)];
            }
        }
    }
}

void orConvolution() {
    sos_dp(fa, sa);
    sos_dp(fb, sb);
    for(int i = 0; i < (1 << n); i++) {
        dp[i] = fa[i] * fb[i]; // cuidado com overflow
    }
    for(int i = n - 1; i >= 0; i--) {
        for(int j = (1 << n) - 1; j >= 0; j--) {
            if(j & (1 << i)) {
                dp[j] -= dp[j ^ (1 << i)];
            }
        }
    }
}