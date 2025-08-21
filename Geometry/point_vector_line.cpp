// Cuidado com overflow nas operações intermediárias
// Cuidado com vetor diretor da reta ser 0

#define PI acos(-1.)
#define rad(t) ((t) * (PI / 180.))

struct point {
    int x, y;
    point() {}
    point(int _x, int _y) : x(_x), y(_y) {}
};

struct vec {
    int x, y;
    vec() {}
    vec(int _x, int _y) : x(_x), y(_y) {}
    vec(point a, point b) : x(b.x - a.x), y(b.y - a.y) {}
};

// Forma paramétrica
struct line {
    point p;
    vec dir;
    line() {}
    line(point _p, vec _dir)   : p(_p), dir(_dir) {}
    line(point a, point b)   : p(a), dir(a, b) {}
};

//cuidado que o retorno aqui pode ser negativo. isso calcula a area do paralelogramo quando
//passado o modulo no resultado, ou seja abs(cross(u, v)). Para ter a area do triangulo,
//multiplicar esse abs do retorno por 0.5 e cuidado com inteiros e doubles.
int cross(vec u, vec v) {
    return u.x * v.y - u.y * v.x;
}

int dot(vec u, vec v) {
    return u.x * v.x + u.y * v.y;
}

bool onLine(line l, point p) {
    return cross(l.dir, vec(l.p, p)) == 0;
}

bool parallel(line l, line r) {
    return cross(l.dir, r.dir) == 0;
}

double linesDist(line l, line r){
    if(!parallel(l, r)) return 0.0;
    vec v(l.p, r.p);
    double area2 = fabs(cross(l.dir, v));  // 2 * area
    double len = sqrt(l.dir.x * l.dir.x + l.dir.y * l.dir.y);
    return area2 / len;
}

double linePointDist(line l, point p){
    vec v(l.p, p);
    double area2 = fabs(cross(l.dir, v));  // 2 * area
    double len = sqrt(l.dir.x * l.dir.x + l.dir.y * l.dir.y);
    return area2 / len;
}

int side(line l, point p) {
    return cross(l.dir, vec(l.p, p));
    // > 0 esq, < 0 dir, 0 = na reta
}

bool intersection(line l, line r, point &res) {
    double d = cross(l.dir, r.dir);
    if(fabs(d) < EPS) return false;
    vec delta(l.p, r.p);
    double t = cross(delta, r.dir) / d;
    res.x = l.p.x + t * l.dir.x;
    res.y =  l.p.y + t * l.dir.y;
    return true;
}

// deg em graus, cuidado se ja estiver em radianos
vec rotateVec(vec u, double deg) {
    double t = rad(deg);
    double x = cos(t) * u.x + (-sin(t) * u.y);
    double y = sin(t) * u.x + cos(t) * u.y;
    return vec(x, y);
}

bool operator<(point a, point b) {
    return a.x < b.x || (a.x == b.x && a.y < b.y);
}

