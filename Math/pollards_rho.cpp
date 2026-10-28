// a função fact retorna os fatores primos do numero, que podem ter repetições
// e não estar em ordem

ll mul(ll a, ll b, ll m) {
    return (__int128)a * b % m;
}

ll pow(ll x, ll y, ll m) {
    if(!y) return 1;
    ll ans = pow(mul(x, x, m), y / 2, m);
    return y % 2 ? mul(x, ans, m) : ans;
}

bool prime(ll n) {
    if(n < 2) return 0;
    if(n <= 3) return 1;
    if(n % 2 == 0) return 0;
    ll r = __builtin_ctzll(n - 1), d = n >> r;
    for(int a : {2, 325, 9375, 28178, 450775, 9780504, 1795265022}) {
        if(a % n == 0) continue;
        ll x = pow(a, d, n);
        if(x == 1 || x == n - 1) continue;
        for(int j = 0; j < r - 1; j++) {
            x = mul(x, x, n);
            if(x == n - 1) break;
        }
        if(x != n - 1) return 0;
    }
    return 1;
}

ll rho(ll n) {
    if(n == 1 or prime(n)) return n;
    ll x = 0, y = 0, t = 30, prd = 2, c = 1, q;
    auto f = [&](ll x) {
        return (ll)((mul(x, x, n) + (__int128)c) % n);
    };
    while(t % 40 != 0 or gcd(prd, n) == 1) {
        if(x == y) {
            c++;
            x = c % n;
            y = f(x);
        }
        q = mul(prd, abs(x - y), n);
        if(q != 0) prd = q;
        x = f(x);
        y = f(f(y));
        t++;
    }
    return gcd(prd, n);
}

vector<ll> fact(ll n) {
    if(n == 1) return {};
    if(prime(n)) return {n};
    ll d = rho(n);
    vector<ll> l = fact(d), r = fact(n / d);
    l.insert(l.end(), r.begin(), r.end());
    return l;
}