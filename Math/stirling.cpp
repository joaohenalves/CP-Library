//aproximação de stirling para a grandeza de n!

double stirling(int n){
    return log(2. * PI * n) * 0.5 + n * (log(n) - 1.) ;
}