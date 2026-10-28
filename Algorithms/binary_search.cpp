bool check(ll guess) {
    //Alguma coisa aqui
    return 0;
}

// min
ll binSearch(ll inf, ll sup) {
    ll mid;
    while(inf < sup) {
        mid = inf + (sup - inf) / 2LL;
        if(check(mid)) sup = mid;
        else inf = mid + 1LL;
    }
    return inf;
}

//max
ll binSearch(ll inf, ll sup) {
    ll mid;
    while(inf < sup) {
        mid = inf + (sup - inf + 1LL) / 2LL;
        if(check(mid) == true) inf = mid;
        else sup = mid - 1LL;
    }
    return inf;
}

//min double
double binSearch(double inf, double sup) {
    for(int i = 0; i < 100; i++) {
        double mid = inf + (sup - inf) / 2.;
        double d = (sup - inf) * 1e-6; // multiplicar por um valor nao muito pequeno, que faça sentido pra precisao do problema
        if(check(mid - d) < check(mid + d)) sup = mid;
        else inf = mid;
    }
    return (inf + sup) / 2.;
}

// cuidado com overflow
// ajustar para 31 caso possa ser utilizado só int mesmo
ll maxBinSearch(ll inf, ll sup) {
    for(ll k = 1LL << 62; k > 0; k >>= 1) {
        if(inf + k <= sup && check(inf + k)) inf += k;
    }
    return inf;
}

ll minBinSearch(ll inf, ll sup) {
    for(ll k = 1LL << 62; k > 0; k >>= 1) {
        if(sup - k >= inf && check(sup - k)) sup -= k;
    }
    return sup;
}

