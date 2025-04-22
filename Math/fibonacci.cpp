int gcd(int a, int b) {
    if(b == 0) return a;
    return gcd(b, a % b);
}

int calcPeriod(int p, int exp) {
    int ans = pow(p, exp - 1);
    if(p == 2) return ans * 3;
    else if(p == 5) return ans * 20;
    else {
        int mod = p % 10;
        if(mod == 1 || mod == 9) return ans * (p - 1);
        else return ans * 2 * (p + 1);
    }
    return 0;
}

int findPeriod(int n) {
    int exp, mod, aux, lcm = 1;
    for(int i = 0; i < pi && primes[i] * primes[i] <= n; i++) {
        exp = 0;
        while(n % primes[i] == 0) {
            n /= primes[i];
            exp++;
        }
        if(exp) {
            aux = calcPeriod(primes[i], exp);
            lcm = lcm * aux / gcd(lcm, aux);
        }
    }
    if(n > 1) {
        aux = calcPeriod(n, 1);
        lcm = lcm * aux / gcd(lcm, aux);
    }
    return lcm;
}

void ident(ll a[2][2]) {
    a[0][0] = a[1][1] = 1;
    a[0][1] = a[1][0] = 0;
}

void multMat(ll a[2][2], ll b[2][2], ll c[2][2], ll mod) {
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            c[i][j] = (a[i][0] * b[0][j] + a[i][1] * b[1][j]) % mod;
        }
    }
}

void expbin(ll a[2][2], ll b[2][2], int n, int mod) {
    ll c[2][2];
    if(n < 0) return;
    if(n == 0) ident(b);
    else if(n & 1) {
        expbin(a, c, n - 1, mod);
        multMat(a, c, b, mod);
    } else {
        expbin(a, c, n >> 1, mod);
        multMat(c, c, b, mod);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, mod;
    ll a[2][2], b[2][2];
    a[0][0] = a[0][1] = a[1][0] = 1; a[1][1] = 0;
    sieve();
    while(cin >> n >> m) {
        mod = findPeriod(m);
        expbin(a, b, n % findPeriod(mod), mod);
        expbin(a, b, b[0][1], m);
        cout << b[0][1] << "\n";
    }
    return 0;
}
