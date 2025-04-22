// retorna a soma de todos os divisores de x

ll sum(int x) {
    ll ans = 1;
    for(int i = 0; i < pi && primes[i] * primes[i] <= x; i++) {
        if(x % primes[i] == 0) {
            int exp = 0;
            while(x % primes[i] == 0) {
                exp++;
                x /= primes[i];
            }
            ans *= (pow(primes[i], exp + 1) - 1) / (primes[i] - 1);
        }
    }
    if(x > 1) ans *= (pow(x, 2) - 1) / (x - 1);
    return ans;
}