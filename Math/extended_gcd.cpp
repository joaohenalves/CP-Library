// calcula o inverso multiplicativo de um numero mod não primo, que pode não existir

ll extended_gcd(ll a, ll b, ll &x, ll &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll x1, y1;
    ll d = extended_gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

ll modInverse(ll a, ll mod) {
    ll x, y;
    ll g = extended_gcd(a, mod, x, y);
    if (g != 1) {
        // a and m aren't relatively prime, so modular inverse doesn't exist
        return -1;
    } else {
        return (x % mod + mod) % mod;
    }
}