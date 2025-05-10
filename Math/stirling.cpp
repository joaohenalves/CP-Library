//aproximação de stirling para a grandeza de n!

double stirling(int n){
    return log(2. * PI * n) * 0.5 + n * (log(n) - 1.) ;
}

// Ou melhor:

ll stirling(ll n){
    // expl(1.0L) = número de euler 2,7182...
    if(n == 0) return 1;
    long double pi = acosl(-1.L);
    return (ll) (log10l(2.L * pi * n) * 0.5L + n * (log10l(n) - log10l(expl(1.0L)))) + 1;
}
