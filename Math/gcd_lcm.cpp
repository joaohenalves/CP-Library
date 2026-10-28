ll gcd(ll a, ll b) {
    if(b == 0LL) return a;
    return gcd(b, a % b);
}

ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}