// Exemplo de uso com manhattan distance
// Coordenadas dos pontos nesse exemplo vão de -500 a 500
// Como eles podem ser negativo, chamar as funções somando 500 em cada
// coordenada, para indexar tudo em 0
// Tamanho do grid deve ser (qtd_diagonais)^2

// Se não for query de manhattan distance, n = linhas e m = colunas

#define MAX 2123
#define left(u) ((u) + 1)
#define right(u, l, m) ((u) + 2 * ((m) - (l) + 1))

int a[MAX][MAX], t[2 * MAX][2 * MAX];

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

void build_y(int vx, int lx, int rx, int vy, int ly, int ry) {
    if(ly == ry) {
        if(lx == rx) t[vx][vy] = a[lx][ly];
        else t[vx][vy] = gcd(t[left(vx)][vy], t[right(vx, lx, (lx + rx) / 2)][vy]);
    } else {
        int my = (ly + ry) / 2;
        build_y(vx, lx, rx, left(vy), ly, my);
        build_y(vx, lx, rx, right(vy, ly, my), my + 1, ry);
        t[vx][vy] = gcd(t[vx][left(vy)], t[vx][right(vy, ly, my)]);
    }
}

void build_x(int vx, int lx, int rx) {
    if(lx != rx) {
        int mx = (lx + rx) / 2;
        build_x(left(vx), lx, mx);
        build_x(right(vx, lx, mx), mx + 1, rx);
    }
    build_y(vx, lx, rx, 0, 0, m - 1);
}

int query_y(int vx, int vy, int tly, int try_, int ly, int ry) {
    if(ly > ry) return 0;
    if(ly == tly && try_ == ry) return t[vx][vy];
    int tmy = (tly + try_) / 2;
    return gcd(
        query_y(vx, left(vy), tly, tmy, ly, min(ry, tmy)),
        query_y(vx, right(vy, tly, tmy), tmy + 1, try_, max(ly, tmy + 1), ry)
    );
}

int query_x(int vx, int tlx, int trx, int lx, int rx, int ly, int ry) {
    if(lx > rx) return 0;
    if(lx == tlx && trx == rx) return query_y(vx, 0, 0, m - 1, ly, ry);
    int tmx = (tlx + trx) / 2;
    return gcd(
        query_x(left(vx), tlx, tmx, lx, min(rx, tmx), ly, ry),
        query_x(right(vx, tlx, tmx), tmx + 1, trx, max(lx, tmx + 1), rx, ly, ry)
    );
}

void update_y(int vx, int lx, int rx, int vy, int ly, int ry, int x, int y, int val) {
    if(ly == ry) {
        if(lx == rx) t[vx][vy] = val;
        else t[vx][vy] = gcd(t[left(vx)][vy], t[right(vx, lx, (lx + rx) / 2)][vy]);
    } else {
        int my = (ly + ry) / 2;
        if(y <= my) update_y(vx, lx, rx, left(vy), ly, my, x, y, val);
        else update_y(vx, lx, rx, right(vy, ly, my), my + 1, ry, x, y, val);
        t[vx][vy] = gcd(t[vx][left(vy)], t[vx][right(vy, ly, my)]);
    }
}

void update_x(int vx, int lx, int rx, int x, int y, int val) {
    if(lx != rx) {
        int mx = (lx + rx) / 2;
        if(x <= mx) update_x(left(vx), lx, mx, x, y, val);
        else update_x(right(vx, lx, mx), mx + 1, rx, x, y, val);
    }
    update_y(vx, lx, rx, 0, 0, m - 1, x, y, val);
}

int manhattan_query(int x, int y, int d) {
    int nx = x + y;
    int ny = x - y + 1050;
    return query_x(0, 0, n - 1, max(nx - d, 0), min(nx + d, n - 1), max(ny - d, 0), min(ny + d, m - 1));
}

void manhattan_update(int x, int y, int val) {
    int nx = x + y;
    int ny = x - y + 1050;
    update_x(0, 0, n - 1, nx, ny, val);
}
