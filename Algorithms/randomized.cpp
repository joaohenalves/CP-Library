#pragma once
#include <random>
#include <vector>
#include <algorithm>
#include <cstdint>

static mt19937_64& RNG() {
    static thread_local mt19937_64 eng(random_device{}());
    return eng;
}

void reseed(uint64_t s) { RNG().seed(s); }                  // opcional: tornar reprodutível

long long randint(long long l, long long r) {               // [l, r] inclusivo
    uniform_int_distribution<long long> d(l, r);
    return d(RNG());
}

uint64_t rand_mod(uint64_t m) {                             // [0, m-1], sem viés
    if (m == 0) return 0;
    uniform_int_distribution<uint64_t> d(0, m - 1);
    return d(RNG());
}

void shuffle_vec(vector<int>& v) {                     // embaralhar vector<int>
    shuffle(v.begin(), v.end(), RNG());
}


// versão simplificada:

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

//funções de int e ll geram numeros no intervalo [l, r]
int rndInt(int l, int r) {
    return uniform_int_distribution<int>(l, r)(rng);
}

ll rndLong(ll l, ll r) {
    return uniform_int_distribution<ll>(l, r)(rng);
}

double rndDouble() {
    return uniform_real_distribution<double>(0.0, 1.0)(rng); // intervalo [0, 1), 1 excluido
}

// exemplo de uso:

int x = rndInt(0, 100); // gera numero randomico de 0 a 100