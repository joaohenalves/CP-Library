const int mod = 998244353; // 199*(1 << 23) + 1
const int root = 15311432; // 3 ^ 119 % mod = 15311432 (3 eh raiz primitiva)
const int root_1 = 469870224; // 15311432 ^ -1 % mod
const int root_pw = 1 << 23;
// Para polinomios com N ate (1 << 23) = 8388608 > 8*10^6

const int mod = 7340033; // 7*(1 << 20) + 1
const int root = 5; // 5 ^ (1 << 20) % mod = 1
const int root_1 = 4404020; // 5 ^ -1 % mod
const int root_pw = 1 << 20;
// Para polinomios com N ate (1 << 20) = 1048576 > 10^6

ll expbin(ll a, ll b) {
    ll ans = 1;
    while(b) {
        if(b & 1) ans = (ans * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return ans;
}

void ntt(vector<int> &a, bool invert) {
    int n = a.size();
    for(int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        for(; j & bit; bit >>= 1) {
            j ^= bit;
        }
        j ^= bit;
        if(i < j) swap(a[i], a[j]);
    }
    for(int len = 2; len <= n; len <<= 1) {
        int wlen = invert ? root_1 : root;
        for(int i = len; i < root_pw; i <<= 1) {
            wlen = (int)(1LL * wlen * wlen % mod);
        }
        for(int i = 0; i < n; i += len) {
            int w = 1;
            for(int j = 0; j < len / 2; j++) {
                int u = a[i + j];
                int v = (int) (1LL * a[i + j + len / 2] * w % mod);
                a[i + j] = u + v < mod ? u + v : u + v - mod;
                a[i + j + len / 2] = u - v >= 0 ? u - v : u - v + mod;
                w = (int) (1LL * w * wlen % mod);
            }
        }
    }
    if(invert) {
        int n_1 = expbin(n, mod - 2);
        for(int &x : a) {
            x = (int)(1LL * x * n_1 % mod);
        }
    }
}

void multiply(vector<int> &a, vector<int> &b) {
    int n = 1;
    while(n < a.size() + b.size()) {
        n <<= 1;
    }
    a.resize(n);
    b.resize(n);
    ntt(a, false);
    ntt(b, false);
    for(int i = 0; i < n; i++) {
        a[i] = (1LL * a[i] * b[i]) % mod;
    }
    ntt(a, true);
}