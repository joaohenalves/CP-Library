// fórmula área do triângulo, incírculo e circuncírculo
typedef tuple<double, double, double> tddd;

tddd calc(double a, double b, double c) {
    double s = (a + b + c) / 2;
    double tri = sqrt(s * (s - a) * (s - b) * (s - c));
    double r = tri / s;
    double inCirc = r * r * PI;
    r = a * b * c / (4 * tri);
    double circC = r * r * PI;
    return make_tuple(tri, inCirc, circC);
}