#include <bits/stdc++.h>
using namespace std;

#define MAX 212345
#define MAXB 2123456
#define LOG 20
#define PI acos(-1.)
#define MAXG 1123
#define INF 1012345678 // 10^9
#define INFLL 1123456789112345678ll //10^18
#define EPS 1e-9
#define MOD 1000000007
#define MODWPP 998244353
typedef long long ll;
typedef unsigned long long ull;
typedef __int128_t i128;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;

int n, m, k, arr[MAXB];
ll x, y, vet[MAXB];
bitset<MAX> b1;
vector<vector<int>> graph(MAX), factors(MAX);
string s;
vector<vector<pair<int, ll>>> pref(MAX, vector<pair<int, ll>> (1));

void factorize() {
    for(int i = 2; i < MAX; i++) {
        if(factors[i].empty()) {
            for(int j = i; j < MAX; j += i) {
                factors[j].push_back(i);
            }
        }
    }
}

bool check(int guess, int i) {
    ll ans = 0ll;
    int sz = (int) factors[i].size();
    for(int j = 1; j < (1 << sz); j++) {
        int nm = 1;
        ll c = -1ll;
        for(int k = 0; k < sz; k++) {
            if(j & (1 << k)) {
                c *= -1ll;
                nm *= factors[i][k];
            }
        }
        int u = lower_bound(pref[nm].begin(), pref[nm].end(), make_pair(guess + 1, -1ll)) - pref[nm].begin();
        ans += c * pref[nm][u - 1].second;
    }
    return ans >= vet[i];
}

int binSearch(int inf, int sup, int i) {
    int mid;
    while(inf < sup) {
        mid = inf + (sup - inf) / 2;
        if(check(mid, i)) sup = mid;
        else inf = mid + 1;
    }
    return inf;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int a, b, c, t, u, v, w, f, q, ans;
    ll la, lb, lc, lans;
    string s1, s2;
    char ch1, ch2;
    factorize();
    cin >> n >> q;
    for(int i = 1; i <= n; i++) {
        cin >> vet[i];
    }
    for(int i = 1; i <= q; i++) {
        cin >> a >> la;
        b = (int) factors[a].size();
        for(int j = 1; j < (1 << b); j++) {
            c = 1;
            for(int k = 0; k < b; k++) {
                if(j & (1 << k)) {
                    c *= factors[a][k];
                }
            }
            pref[c].emplace_back(i, pref[c].back().second + la);
        }
    }
    for(int i = 1; i <= n; i++) {
        ans = binSearch(0, q, i);
        if(check(ans, i) == 0) ans = -1;
        cout << ans << '\n';
    }
    return 0;
}