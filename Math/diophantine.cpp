// Solução para ax + by = c, onde a, b e c são conhecidos
// encontra se existem x e y não negativos que satisfaçam a equação
// se x e y podem ser negativos, usar só a  função find_any_solution
// não funciona se a = b = 0

int egcd(int a, int b, int& x, int& y) {
    if(b == 0) { x = 1; y = 0; return a; }
    int x1, y1;
    int g = egcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return g;
}

bool find_any_solution(int a, int b, int c, ll &x0, ll &y0, ll &g) {
    int x, y;
    g = egcd(abs(a), abs(b), x, y);
    if(c % g) return false;
    x0 = (ll)x * (c / g);
    y0 = (ll)y * (c / g);
    if(a < 0) x0 = -x0;
    if(b < 0) y0 = -y0;
    return true;
}

ll floordiv(ll p, ll q) {
    if(p >= 0) return p / q;
    return -(( -p + q - 1 ) / q);
}

ll ceildiv(ll p, ll q) {
    if(p >= 0) return (p + q - 1) / q;
    return -((-p) / q);
}

bool find_solution_nonneg(int a, int b, int c, ll &x, ll &y) {
    ll x0, y0, g;
    if(!find_any_solution(a, b, c, x0, y0, g)) return false;
    ll bg = b / g, ag = a / g;
    ll kmin = ceildiv(-x0, bg);
    ll kmax = floordiv(y0, ag);
    if (kmin > kmax) return false;
    ll k = kmin;
    x = x0 + k * bg;
    y = y0 - k * ag;
    return true;
}