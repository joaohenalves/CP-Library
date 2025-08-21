ll inv[MAX];

void modInverse() {
    inv[0] = inv[1] = 1;
    for(ll i = 2; i <= n; i++) {
        inv[i] = ((MOD - MOD / i) * inv[MOD % i]) % MOD;
    }
}