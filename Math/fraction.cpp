struct frac {
    ll a, b = 1LL;
    frac() {}
    frac(ll _a) : a(_a) {}
    frac(ll _a, ll _b) : a(_a), b(_b) {}
    bool operator <(const frac &f) const {
        return a * f.b < b * f.a;
    }
};