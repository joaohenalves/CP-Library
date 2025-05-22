// Problema muito difícil: https://atcoder.jp/contests/abc384/tasks/abc384_g
// dados dois arrays x e y de tamanho n e dadas k queres do tipo i, j, processar
// somatorio(1 até i, somatorio(1 até j, abs(x[i] - y[j])))
// números indo de 1 até 10^8, utilizado compressão de índices para ajudar
// BSIZE ótimo aqui: n / sqrt(k)

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
typedef long long ll;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;

int n, m, k, arr[MAX];
ll current, vet[MAX], ans[MAX], x[MAX], y[MAX], mpx[MAX], mpy[MAX], unmap[MAX];
bitset<MAX> b1;
vector<vector<int>> graph(MAX);

void compress() {
    map<int, int> remap;
    int idx = 0;
    for(int i = 0; i < 2 * n; i++) {
        remap[arr[i]] = 0;
    }
    for(auto &[key, val] : remap) {
        unmap[idx] = key;
        val = idx++;
    }
    for(int i = 0; i < n; i++) {
        mpx[i] = remap[x[i]];
        mpy[i] = remap[y[i]];
    }
}


#define left(u) (2 * (u))
#define right(u) (left(u) + 1)

ll st[2][2 * MAX][2];

ll query(int f, int l, int r, ll val) {
    ll ans = 0, sz = 0;
    for(l += 2 * n, r += 2 * n; l <= r; ++l /= 2, --r /= 2) {
        if(l % 2 == 1) {
            ans += st[f][l][0];
            sz += st[f][l][1];
        }
        if(r % 2 == 0) {
            ans += st[f][r][0];
            sz += st[f][r][1];
        }
    }
    return llabs(sz * val - ans);
}

void update(int f, int u, ll delta, ll val) {
    st[f][u += 2 * n][1] += delta;
    st[f][u][0] = st[f][u][1] * val;
    while(u /= 2) {
        st[f][u][0] = st[f][left(u)][0] + st[f][right(u)][0];
        st[f][u][1] = st[f][left(u)][1] + st[f][right(u)][1];
    }
}

const int BSIZE = 1000;
vector<tiii> queries(MAX);

bool comp(const tiii a, const tiii b) {
    auto [al, ar, ai] = a;
    auto [bl, br, bi] = b;
    if(al / BSIZE != bl / BSIZE) return a < b;
    return (al / BSIZE & 1) ? (ar < br) : (ar > br);
}

void removex(int i) {
    int j = mpx[i];
    current -= query(1, 0, j - 1, x[i]) + query(1, j + 1, 2 * n - 1, x[i]);
    update(0, j, -1, x[i]);
}

void addx(int i) {
    int j = mpx[i];
    current += query(1, 0, j - 1, x[i]) + query(1, j + 1, 2 * n - 1, x[i]);
    update(0, j, 1, x[i]);
}

void removey(int i) {
    int j = mpy[i];
    current -= query(0, 0, j - 1, y[i]) + query(0, j + 1, 2 * n - 1, y[i]);
    update(1, j, -1, y[i]);
}

void addy(int i) {
    int j = mpy[i];
    current += query(0, 0, j - 1, y[i]) + query(0, j + 1, 2 * n - 1, y[i]);
    update(1, j, 1, y[i]);
}

ll getAns() {
    return current;
}

void mo() {
    sort(queries.begin(), queries.begin() + k, comp);
    int l = -1, r = -1;
    for(int i = 0; i < k; i++) {
        auto &[ql, qr, j] = queries[i];
        while(l > ql) {
            removex(l);
            l--;
        }
        while(l < ql) {
            l++;
            addx(l);
        }
        while(r > qr) {
            removey(r);
            r--;
        }
        while(r < qr) {
            r++;
            addy(r);
        }
        ans[j] = getAns();
    }
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int a, b, c, t, u, v, w, f, q;
	ll la, lb, lc, lans;
    string s1, s2;
    char ch1, ch2;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> x[i];
        arr[i] = x[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> y[i];
        arr[i + n] = y[i];
    }
    compress();
    cin >> k;
    for(int i = 0; i < k; i++) {
        cin >> a >> b;
        a--; b--;
        queries[i] = {a, b, i};
    }
    mo();
    for(int i = 0; i < k; i++) {
        cout << ans[i] << '\n';
    }
    return 0;
}
