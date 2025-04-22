// função totiente de euler

int phi(int x) {
    int exp, ans = 1;
    for(int i = 0; i < pi; i++) {
        if(primes[i] * primes[i] > x) break;
        exp = 0;
        while(x % primes[i] == 0) {
            exp++;
            x /= primes[i];
        }
        if(exp) {
            ans *= (primes[i] - 1) * pow(primes[i], exp - 1);
        }
    }
    if(x > 1) ans *= (x - 1);
    return ans;
}