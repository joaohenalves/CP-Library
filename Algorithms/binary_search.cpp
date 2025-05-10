bool check(ll guess) {
    //Alguma coisa aqui
    return 0;
}

ll binSearch(ll inf, ll sup) {
    ll mid;
    while(inf < sup) {
        mid = inf + (sup - inf) / 2;
        if(check(mid)) sup = mid;
        else inf = mid + 1;
    }
    return inf;
}

// cuidado com overflow
// ajustar para 31 caso possa ser utilizado só int mesmo
ll maxBinSearch(ll inf, ll sup) {
    for(ll k = 1LL << 62; k > 0; k >>= 1LL) {
        if(inf + k <= sup && check(inf + k)) inf += k;
    }
    return inf;
}

ll minBinSearch(ll inf, ll sup) {
    for(ll k = 1LL << 62; k > 0; k >>= 1LL) {
        if(sup - k >= inf && check(sup - k)) sup -= k;
    }
    return sup;
}

