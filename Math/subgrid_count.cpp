//Cuidado com possível overflow

//Conta quantos subgrids existem ((n + 1 escolhe 2) * (m + 1 escolhe 2))
ll totalSubgrids(ll n, ll m) {
    return (n * (n + 1LL) / 2LL) * (m * (m + 1LL) / 2LL);
}

//Conta quantos subgrids de tamanho a x b existem (sem rotacionar);
//Somente quando a != b
ll fixedSubgrids(ll n, ll m, ll a, ll b) {
    return (n - a + 1LL) * (m - b + 1LL);
}

//Conta quantos subgrids de tamanho a x b existem (com rotação);
//Somente quando a != b
ll rotFixedSubgrids(ll n, ll m, ll a, ll b) {
    return (n - a + 1LL) * (m - b + 1LL) + (n - b + 1LL) * (m - a + 1LL);
}

//Conta quantos quadrados de lado k existem
ll totalSquares(ll m, ll n, ll k) {
    ll s = min(n, m);
    return s * (n + 1LL) * (m + 1LL) - ((n + m + 2LL) * s * (s + 1LL) / 2LL);
}