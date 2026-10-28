// Exemplo de uso com manhattan distance
// Coordenadas dos pontos nesse exemplo vão de -500 a 500
// Como eles podem ser negativo, chamar as funções somando 500 em cada
// coordenada, para indexar tudo em 0
// Tamanho do grid deve ser (qtd_diagonais)^2

#define left(p) (p << 1)
#define right(p) (left(p) + 1)

int st[2 * MAX][2 * MAX];

int gcd(int a, int b) {
    if(b == 0) return a;
    return gcd(b, a % b);
}

void build() {
    for(int x = 2 * n; x; x--) {
        for(int y = 2 * n; y; y--) {
            if(x < n) st[x][y] = gcd(st[left(x)][y], st[right(x)][y]);
            if(y < n) st[x][y] = gcd(st[x][left(y)], st[x][right(y)]);
        }
    }
}

int query(int x1, int y1, int x2, int y2) {
    int ret = 0, y3 = y1 + n, y4 = y2 + n;
    for(x1 += n, x2 += n; x1 <= x2; (++x1) >>= 1, (--x2) >>= 1) {
        for(y1 = y3, y2 = y4; y1 <= y2; (++y1) >>= 1, (--y2) >>= 1) {
            if(ret == 1) return ret;
            if((x1 & 1) && (y1 & 1)) ret = gcd(ret, st[x1][y1]);
            if((x1 & 1) && !(y2 & 1)) ret = gcd(ret, st[x1][y2]);
            if(!(x2 & 1) && (y1 & 1)) ret = gcd(ret, st[x2][y1]);
            if(!(x2 & 1) && !(y2 & 1)) ret = gcd(ret, st[x2][y2]);
        }
    }
    return ret;
}

void update(int x, int y, int val) {
    int y2 = y += n;
    for(x += n; x; x >>= 1, y = y2) {
        if(x >= n) st[x][y] = val;
        else st[x][y] = gcd(st[left(x)][y], st[right(x)][y]);
        while(y >>= 1) st[x][y] = gcd(st[x][left(y)], st[x][right(y)]);
    }
}

void insert_val(int x, int y, int val) {
    st[x + n][y + n] = val;
}

int manhattan_query(int x, int y, int d) {
    int nx = x + y, ny = x - y + 1000;
    return query(max(nx - d, 0), max(ny - d, 0), min(nx + d, n), min(ny + d, n));
}

void manhattan_update(int x, int y, int val) {
    int nx = x + y, ny = x - y + 1000;
    update(nx, ny, val);
}