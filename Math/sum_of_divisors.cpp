// retorna a soma de todos os divisores de x
// seja a decomposição em potencias de primos de um numero x como:
// p_1^(k_1) * p_2^(k_2) * ...
// cada potencia de primo gera o termo da formula
// (p_i^((k_i) + 1) - 1) / (p_i - 1)
// lê-se: eleva o primo p a (k + 1), subtrai 1 disso, divide por (p - 1)
// o resultado da formula é o produto de todos esses termos

// TODO: melhorar esse codigo pra nao usar pow

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