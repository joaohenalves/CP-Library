ll expbin(ll a, ll b) {
    if(b == 0) return 1;
    if(b & 1) return a * expbin(a, b - 1) % MOD;
    ll c = expbin(a, b >> 1);
    return c * c % MOD;
}

ll expbin(ll a, ll b) {
    ll ans = 1;
    while(b) {
        if(b & 1) ans = ans * a;
        a = a * a;
        b >>= 1;
    }
    return ans;
}