#include <bits/stdc++.h>
using namespace std;

#define MAX 212345
#define LOG 20
#define PI acos(-1.)
#define MAXG 1123
#define INF 1123456789
#define INFLL 112345678911234567
#define EPS 1e-9
#define MOD 1000000007
#define MODWPP 998244353
typedef long long ll;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;

int n, m, k, arr[MAX], cf[MAX], v1[MAX], v2[MAX], base[MAX];
ll vet[MAX];
bitset<MAX> b1;
vector<vector<int>> graph(MAX);
vector<vector<int>> precalc(LOG);

const int mod = 998244353;
const int root = 15311432;
const int root_1 = 469870224;
const int root_pw = 1 << 23;

ll expbin(ll a, ll b) {
    ll ans = 1;
    while(b) {
        if(b & 1) ans = (ans * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return ans;
}

void ntt(int a[], bool invert) {
    int n = k;
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
        for(int i = 0; i < n; i++) {
            a[i] = (int)(1LL * a[i] * n_1 % mod);
        }
    }
}

void multiply(int a[], int b[]) {
    int n0 = 1;
    while(n0 < n + m) {
        n0 <<= 1;
    }
    k = n0;
    ntt(a, false);
    ntt(b, false);
    for(int i = 0; i < k; i++) {
        a[i] = (1LL * a[i] * b[i]) % mod;
    }
    ntt(a, true);
    ntt(b, true);
    m += n - 1;
}

void polyExp(int p[], int exp) {
    for(int i = 0; i < m; i++) {
        base[i] = p[i];
    }
    for(int i = 0; i < exp; i++) {
        if(i == 0) cf[0] += v1[0];
        else multiply(p, base);
        for(int j = 0; j < m; j++) {
            cf[j] += (1LL * p[j] * v1[i + 1]) % mod;
            cf[j] %= mod;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int a, b, c, t, u, v, w, f, q, ans;
    ll la, lb, lc, lans;
    string s1, s2;
    char ch1, ch2;
    cin >> a;
    a++;
    for(int i = 0; i < a; i++) {
        cin >> v1[i];
    }
    cin >> m;
    m++;
    n = m;
    for(int i = 0; i < m; i++) {
        cin >> v2[i];
    }
    polyExp(v2, a - 1);
    for(int i = 0; i < m; i++) {
        cout << cf[i] << ' ';
    }
    cout << '\n';
    return 0;
}