// Conta quantos dígitos existem em todos os números de 1 a n

ll totalDigits(ll n) {
    ll lans = 0LL;
    for(ll i = 1LL; i <= n; i *= 10LL) {
        lans += (n - i + 1LL);
    }
    return lans;
}

// Computa a soma de todos os dígitos dos números de 1 a n

ll dp(ll n, vector<ll> &dg) {
    if(n < 10) return (n * (n + 1LL) / 2LL);
    int d = (int)(log10(n));
    ll p = (ll)(ceil(pow(10, d)));
    ll msd = n / p;
    return (msd * dg[d] + (msd * (msd - 1LL) / 2LL) * p
            + msd * (1LL + n % p) + dp(n % p, dg));
}

ll sumOfDigits(ll n) {
    int d = max(((int)(log10(n))), 1);
    vector<ll> dg(d + 1);
    dg[0] = 0;
    dg[1] = 45;
    for(int i = 2; i <= d; i++) {
        dg[i] = dg[i - 1] * 10LL + 45LL * (ll)(ceil(pow(10, i - 1)));
    }
    return dp(n, dg);
}