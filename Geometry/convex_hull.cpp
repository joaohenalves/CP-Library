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

bool operator<(point a, point b) {
    return a.x < b.x || (a.x == b.x && a.y < b.y);
}

point p[MAX], hull[2 * MAX];

int cross(vec u, vec v) {
    return (u.x * v.y - u.y * v.x) < 0;
}

void convexHull() {
    k = 0;
    sort(p, p + n);
    for(int i = 0; i < n; i++) {
        while(k >= 2 && !cross(vec(hull[k - 2], p[i]), vec(hull[k - 2], hull[k - 1]))) {
            k--;
        }
        hull[k++] = p[i];
    }
    for(int i = n - 2, t = k + 1; i >= 0; i--) {
        while(k >= t && !cross(vec(hull[k - 2], p[i]), vec(hull[k - 2], hull[k - 1]))) {
            k--;
        }
        hull[k++] = p[i];
    }
}