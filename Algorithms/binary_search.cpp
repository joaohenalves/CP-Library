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