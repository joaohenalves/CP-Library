// cuidado com 0 e 1 no factorize, 0 vai rodar pra sempre, 1 pode ser confundido com primo

int pi;
ll primes[MAX];
bool isPrime[MAX];

void sieve() {
    memset(isPrime, 1, sizeof(isPrime));
    for(int i = 2; i * i < MAX; i++) {
        if(isPrime[i]) {
            for(int j = i * i; j < MAX; j += i) {
                isPrime[j] = 0;
            }
        }
    }
    pi = 0;
    for(int i = 2; i < MAX; i++) {
        if(isPrime[i]) primes[pi++] = i;
    }
}

vector<pii> factorize(ll x) {
    vector<pii> ans;
    for(int i = 0; i < pi; i++) {
        if(x % primes[i] == 0) {
            int exp = 0;
            while(x % primes[i] == 0) {
                exp++;
                x /= primes[i];
            }
            ans.emplace_back(primes[i], exp);
        }
        if(primes[i] * primes[i] > x) break;
    }
    if(x != 1) ans.emplace_back(x, 1);
    return ans;
}

//Crivo número de divisores (n log n)

int divisors[n + 1];
for(int i = 1; i <= n; i++)
    for(int j = i; j <= n; j += i)
        divisors[j]++;


//Crivo soma dos divisores (n log n)
int sumdiv[n + 1];
for(int i = 1; i <= n; i++)
    for(int j = i; j <= n; j += i)
        sumdiv[j] += i;


//Crivo Totiente de Euler (n log log n)
int totient[n + 1];
for(int i = 1; i <= n; i++) totient[i] = i;
for(int i = 2; i <= n; i++)
    if(totient[i] == i)
        for(int j = i; j <= n; j += i)
            totient[j] -= totient[j] / i;


//Crivo maior divisor primo (n log log n)
int big[n + 1] = {1, 1};
for(int i = 1; i <= n; i++)
    if(big[i] == 1)
        for(int j = i; j <= n; j += i)
            big[j] = i;
