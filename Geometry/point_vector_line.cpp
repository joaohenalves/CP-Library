// Cuidado com overflow nas operações intermediárias
// Cuidado com vetor diretor da reta ser 0

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
    ll area2 = llabs(cross(l.dir, v));  // 2 * area
    double len = sqrt((double) l.dir.x * l.dir.x + (double) l.dir.y * l.dir.y);
    return area2 / len;
}

double linePointDist(line l, point p){
    vec v(l.p, p);
    int area2 = abs(cross(l.dir, v));  // 2 * area
    double len = sqrt((double) l.dir.x * l.dir.x + (double) l.dir.y * l.dir.y);
    return (double) area2 / len;
}

int side(line l, point p) {
    return cross(l.dir, vec(l.p, p));
    // > 0 esq, < 0 dir, 0 = na reta
}

bool intersection(line l, line r, pair<double,double>& res) {
    ll d = cross(l.dir, r.dir);
    if(d == 0) return false;  // retas paralelas ou incidentes
    vec delta(l.p, r.p);
    double t = (double) cross(delta, r.dir) / (double) d;
    res.first = (double) l.p.x + t * (double) l.dir.x;
    res.second = (double) l.p.y + t * (double) l.dir.y;
    return true;
}

bool operator<(point a, point b) {
    return a.x < b.x || (a.x == b.x && a.y < b.y);
}

