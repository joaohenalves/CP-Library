ll check(ll guess) {
    //Alguma coisa aqui
    return 0;
}

ll ternarySearch(ll l, ll r) {
    ll a, b, fa, fb, ans;
    while(r - l >= 3) {
        a = l + (r - l) / 3;
        b = r - (r - l) / 3;
        fa = check(a);
        fb = check(b);
        if(fa < fb) r = b;
        else l = a;
    }
    ans = LLONG_MAX;
    for(int i = l; i <= r; i++) {
        ans = min(ans, check(i));
    }
    return ans;
}