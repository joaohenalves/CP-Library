int pi;

vector<ll> sieve(int n) {
    vector<ll> ans;
    vector<bool> isPrime(n + 1, 1);
    for(int i = 2; i * i <= n; i++) {
        if(isPrime[i]) {
            for(int j = i * i; j <= n; j += i) {
                isPrime[j] = 0;
            }
        }
    }
    for(int i = 2; i <= n; i++) {
        if(isPrime[i]) ans.push_back(i);
    }
    return ans;
}

vector<ll> segmentedSieve(ll l, ll r) {
    l = max(l, 2LL);
    vector<bool> isPrime(r - l + 1, 1);
    vector<ll> ans;
    vector<ll> primes = sieve((int) sqrt(r) + 1);
    for(ll p : primes) {
        for(ll j = max(p * p, ((l + p - 1) / p) * p); j <= r; j += p) {
            isPrime[j - l] = 0;
        }
    }
    for(ll i = 0; i < r - l + 1; i++) {
        if(isPrime[i]) {
           ans.push_back(l + i);
        }
    }
    pi = ans.size();
    return ans;
}