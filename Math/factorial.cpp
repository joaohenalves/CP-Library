// logicamente cuidado com y < 0 ou y > x, que tem que ser 0

ll fact[MAX], inv[MAX];

ll expbin(ll a, ll b) {
    if(b == 0LL) return 1LL;
    if(b & 1LL) return a * expbin(a, b - 1LL) % (ll) MOD;
    ll c = expbin(a, b >> 1);
    return c * c % (ll) MOD;
}

void process() {
    fact[0] = 1LL;
    for(int i = 1; i < MAX; i++) {
        fact[i] = (ll) i * fact[i - 1] % (ll) MOD;
    }
    inv[MAX - 1] = expbin(fact[MAX - 1], (ll) MOD - 2LL);
    for(int i = MAX - 2; i >= 0; i--) {
        inv[i] = (ll) (i + 1) * inv[i + 1] % (ll) MOD;
    }
}

ll nCk(int x, int y) {
    return fact[x] * (inv[y] * inv[x - y] % (ll) MOD) % (ll) MOD;
}