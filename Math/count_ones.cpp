// conta para cada bit quantos desses bits ligados
// existem em todos os numeros de 1 a x

ll ones[64];

void solve(ll x) {
    for(int i = 61; i >= 0; i--) {
        ll y = x >> i;
        ones[i] += (y >> 1) * (1LL << i);
        if(y & 1LL) ones[i] += x % (1LL << i) + 1LL;
    }
}