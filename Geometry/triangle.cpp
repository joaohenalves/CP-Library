// fórmula área do triângulo, incírculo e circuncírculo

tiii calc(int a, int b, int c) {
    int s = (a + b + c) / 2;
    int tri = sqrt(s * (s - a) * (s - b) * (s - c));
    int r = tri / s;
    int inCirc = r * r * PI;
    r = a * b * c / (4 * tri);
    int circC = r * r * PI;
    return make_tuple(tri, inCirc, circC);
}