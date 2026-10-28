ll chinese_remainder(const ll rs[3], const ll ls[3]) {
    ll n = ls[0] * ls[1] * ls[2];
    ll solution = 0;
    for(int i = 0; i < 3; i++) {
        ll y = n / ls[i];
        ll z = inv_modulo(y, ls[i]);
        solution += rs[i] * y * z;
    }
    solution = (n + (solution % n)) % n;
    return (solution == 0 ? n : solution);
}