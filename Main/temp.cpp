#include <bits/stdc++.h>
using namespace std;

#define MAX 212345
#define MAXB 2123456
#define LOG 20
#define PI acos(-1.)
#define MAXG 1123
#define INF 1123456789
#define INFLL 1123456789112345678LL //10^18
#define EPS 1e-9
#define MOD 1000000007
#define MODWPP 998244353
typedef long long ll;
typedef __int128_t i128;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;

int n, m, k, arr[MAXB], face[MAX];
ll vet[MAXB];
bitset<MAX> b1;
vector<vector<int>> graph(MAX);

const int BSIZE = 450;
int fcnt[BSIZE], tot[BSIZE], flip[BSIZE];
ll block[BSIZE], lazy[BSIZE], tak[MAX];

void preprocess() {
    for(int i = 0; i < n; i++) {
        face[i] = 1;
        tot[i / BSIZE]++;
        fcnt[i / BSIZE]++;
    }
}

void doFlip(int bl) {
    flip[bl] = 0;
    block[bl] = 0LL;
    fcnt[bl] = 0;
    for(int i = bl * BSIZE; i < min(n, (bl + 1) * BSIZE); i++) {
        face[i] ^= 1;
        tak[i] = 0LL;
        fcnt[bl] += face[i];
    }
}

void applyLazy(int bl) {
    ll ans = 0LL;
    for(int i = bl * BSIZE; i < min(n, (bl + 1) * BSIZE); i++) {
        if(face[i]) {
            tak[i] += lazy[bl];
            ans = max(ans, tak[i]);
        }
    }
    lazy[bl] = 0LL;
    block[bl] = ans;
}

ll query(int l, int r) {
    int bl = l / BSIZE, br = r / BSIZE;
    ll ans = 0;
    if(bl == br) {
        for(int i = l; i <= r; i++) ans += arr[i];
    } else {
        for(int i = l; i < (bl + 1) * BSIZE; i++) ans += arr[i];
        for(int i = bl + 1; i < br; i++) ans += block[i];
        for(int i = br * BSIZE; i <= r; i++) ans += arr[i];
    }
    return ans;
}

void update1(int l, int r, ll x) {
    int bl = l / BSIZE, br = r / BSIZE;
    if(bl == br) {
        if(flip[bl]) doFlip(bl);
        if(lazy[bl]) applyLazy(bl);
        for(int i = l; i <= r; i++) {
            if(face[i]) tak[i] += x;
            block[bl] = max(block[bl], tak[i]);
        }
    } else {
        if(flip[bl]) doFlip(bl);
        for(int i = l; i < (bl + 1) * BSIZE; i++) {
            if(face[i]) tak[i] += x;
            block[bl] = max(block[bl], tak[i]);
        }
        for(int i = bl + 1; i < br; i++) {
            lazy[i] += x;
            if(flip[i]) {
                if(tot[i] - fcnt[i]) block[i] = lazy[i];
                else block[i] = 0LL;
            } else {
                if(fcnt[i]) block[i] += x;
            }
        }
        if(flip[br]) doFlip(br);
        if(lazy[br] > 0LL) applyLazy(br);
        for(int i = br * BSIZE; i <= r; i++) {
            if(face[i]) tak[i] += x;
            block[br] = max(block[br], tak[i]);
        }
    }
}

void update2(int l, int r) {
    int bl = l / BSIZE, br = r / BSIZE;
    if(bl == br) {
        if(flip[bl]) doFlip(bl);
        if(lazy[bl]) applyLazy(bl);
        for(int i = l; i <= r; i++) {
            if(face[i]) {
                tak[i] = 0LL;
                fcnt[bl] -= face[i];
                face[i] ^= 1;
                fcnt[bl] += face[i];
            }
        }
        block[bl] = 0LL;
        for(int i = bl * BSIZE; i < min(n, (bl + 1) * BSIZE); i++) {
            block[bl] = max(block[bl], tak[i]);
        }
    } else {
        if(flip[bl]) doFlip(bl);
        if(lazy[bl]) applyLazy(bl);
        for(int i = l; i < (bl + 1) * BSIZE; i++) {
            if(face[i]) {
                tak[i] = 0LL;
                fcnt[bl] -= face[i];
                face[i] ^= 1;
                fcnt[bl] += face[i];
            }
        }
        block[bl] = 0LL;
        for(int i = bl * BSIZE; i < (bl + 1) * BSIZE; i++) {
            block[bl] = max(block[bl], tak[i]);
        }

        for(int i = bl + 1; i < br; i++) {
            lazy[i] = 0LL;
            block[i] = 0LL;
            flip[i] ^= i;
            fcnt[]
        }

        if(flip[br]) doFlip(br);
        if(lazy[br]) applyLazy(br);
        for(int i = br * BSIZE; i <= r; i++) {
            if(face[i]) {
                tak[i] = 0LL;
                fcnt[br] -= face[i];
                face[i] ^= 1;
                fcnt[br] += face[i];
            }
        }
        block[br] = 0LL;
        for(int i = br * BSIZE; i < min(n, (br + 1) * BSIZE); i++) {
            block[br] = max(block[br], tak[i]);
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
    cin >> n >> q;
    preprocess();
    while(q--) {
        cin >> a >> u >> v;
        u--; v--;
        if(a == 1) {
            cin >> la;
            update(u, v, la);
        } else if(a == 2) {
            flip(u, v);
        } else {
            cout << query(u, v) << '\n';
        }
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

#define MAX 212345
#define MAXB 2123456
#define LOG 20
#define PI acos(-1.)
#define MAXG 1123
#define INF 1012345678 // 10^9
#define INFLL 1123456789112345678LL //10^18
#define EPS 1e-9
#define MOD 1000000007
#define MODWPP 998244353
typedef long long ll;
typedef __int128_t i128;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;
typedef tuple<ll, pii, pii> crazy;

int n, m, k, arr[MAXB], res[MAX];
ll vet[MAXB], pref[MAX];
bitset<MAX> b1;
vector<vector<int>> graph(MAX);

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int a, b, c, t, u, v, w, f, q, ans;
    ll la, lb, lc, lans;
    string s1, s2;
    char ch1, ch2;
    cin >> t;
    while(t--) {
        cin >> n;
        set<pii> seg;
        iota(res, res + n, 1);
        a = 0;
        for(int i = 0; i < n; i++) {
            cin >> vet[i];
            if(vet[i] < 0LL) {
                if(a > 0) {
                    seg.insert({i - a, i - 1});
                    a = 0;
                }
            } else a++;
            pref[i + 1] = vet[i] + pref[i];
        }
        for(int i = 1; i <= n; i++) {
            pref[i] += pref[i - 1];
        }
        if(a > 0) seg.insert({n - a, n - 1});
        // for(auto  [x, y] : seg) {
        //     cout << x << ' ' << y << '\n';
        // }
        priority_queue<crazy, vector<crazy>, greater<crazy>> pq;
        
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

#define MAX 212345
#define MAXB 2123456
#define LOG 20
#define PI acos(-1.)
#define MAXG 1123
#define INF 1012345678 // 10^9
#define INFLL 1123456789112345678LL //10^18
#define EPS 1e-9
#define MOD 1000000007
#define MODWPP 998244353
typedef long long ll;
typedef __int128_t i128;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;

int n, m, k, flag, arr[MAXB], vis[MAX][11];
ll vet[MAXB];
bitset<MAX> b1;
vector<vector<int>> graph(MAX);
vector<string> days(MAX);

void dfs(int u, int d) {
    if(vis[u][d] == 1) {
        flag = 1;
        return;
    }
    vis[u][d] = 1;
    if(days[u][(d + 1) % k] == 'o') dfs(u, (d + 1) % k);
    for(int v : graph[u]) {
        if(days[v][(d + 1) % k] == 'o') {
            dfs(v, (d + 1) % k);
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
    cin >> t;
    while(t--) {
        cin >> n >> m;
        set<pii> st;
        for(int i = 0; i < m; i++) {
            cin >> u >> v;
            u--; v--;
            if(st.count({u, v}) == 0) {
                graph[u].push_back(v);
                graph[v].push_back(u);
                st.insert({u, v});
            }
        }
        cin >> k;
        for(int i = 0; i < n; i++) {
            fill(vis[i], vis[i] + k, 0);
            cin >> days[i];
        }
        flag = 0;
        for(int i = 0; i < n; i++) {
            if(flag == 0 && vis[i][0] == 0 && days[i][0] == 'o') {
                dfs(i, 0);
            }
        }
        cout << (flag ? "Yes" : "No") << '\n';
        for(int i = 0; i  < n; i++)  {
            graph[i].clear();
        }
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

#define MAX 212345
#define MAXB 2123456
#define LOG 20
#define PI acos(-1.)
#define MAXG 1123
#define INF 1012345678 // 10^9
#define INFLL 1123456789112345678LL //10^18
#define EPS 1e-9
#define MOD 1000000007
#define MODWPP 998244353
typedef long long ll;
typedef __int128_t i128;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;

int n, m, k, arr[MAXB];
ll vet[MAXB], vet2[MAX];
bitset<MAX> b1;
vector<vector<int>> graph(MAX);

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int a, b, c, t, u, v, w, f, q, ans;
    ll la, lb, lc, ld, lans;
    string s1, s2;
    char ch1, ch2;
    cin >> t;
    while(t--) {
        cin >> n;
        u = 0;
        multiset<ll> st;
        for(int i = 0; i < n; i++) {
            cin >> vet[i];
            if(vet[i] > vet[u]) {
                u = i;
            }
            st.insert(vet[i]);
        }
        lc = 0LL;
        for(ll i = 0LL; i <= (ll) n; i++) {
            if(st.count(i) == 0) {
                lc = i;
                break;
            }
        }
        cout << lc << " mex\n";
        ld = lb = 0LL;
        for(ll i = 0LL; i < lc; i++) {
            ld += i + 1LL;
            lb += i;
        }
        la = vet[u] * (ll) n + ld;
        lb += ((ll) n - lc) * (vet[u] + lc) + ld;
        if(lc == vet[u] + 1LL) {
            la += ((ll) n - lc) * lc;
        } else {
            la += ((ll) n - lc - 1LL) * lc;
        }
        cout << la << ' ' << lb << '\n';
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

#define MAX 212345
#define MAXB 2123456
#define LOG 20
#define PI acos(-1.)
#define MAXG 1123
#define INF 1012345678 // 10^9
#define INFLL 1123456789112345678LL //10^18
#define EPS 1e-9
#define MOD 1000000007
#define MODWPP 998244353
typedef long long ll;
typedef __int128_t i128;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;

int n, m, k, arr[MAXB], flip[MAXB];
ll vet[MAXB], memo[MAXB][2];
bitset<MAX> b1;
vector<vector<int>> graph(MAX);

ll dp(int i, int f) {
    if(i < 0) return 0LL;
    if(memo[i][f] != -1LL) return memo[i][f];
    ll la, lb, lans = 0LL;
    if(f) {
        la = dp(i - 1, f) - vet[i];
        lb = vet[i] < 0LL ? dp(i - 1, 0) + vet[i] : INFLL;
        if(lb < la) {
            flip[i] = 1;
            lans = lb;
        } else lans = la;
    } else {
        la = dp(i - 1, f) + vet[i];
        lb = vet[i] < 0LL ? dp(i - 1, 0) - vet[i] : INFLL;
        if(lb < la) {
            flip[i] = 1;
            lans = lb;
        } else lans = la;
    }
    return memo[i][f] = lans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int a, b, c, t, u, v, w, f, q, ans;
    ll la, lb, lc, lans;
    string s1, s2;
    char ch1, ch2;
    cin >> t;
    while(t--) {
        cin >> n;
        fill(flip, flip + n, 0);
        for(int i = 0; i < n; i++) {
            cin >> vet[i];
            memo[i][0] = memo[i][1] = -1LL;
        }
        cout << dp(n - 1, 0) << '\n';
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

#define MAX 212345
#define MAXB 2123456
#define LOG 20
#define PI acos(-1.)
#define MAXG 1123
#define INF 1012345678 // 10^9
#define INFLL 1123456789112345678LL //10^18
#define EPS 1e-9
#define MOD 1000000007
#define MODWPP 998244353
typedef long long ll;
typedef __int128_t i128;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;

int n, m, k, arr[MAXB];
ll vet[MAXB];
bitset<MAX> b1;
vector<vector<int>> graph(MAX);

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int a, b, c, t, u, v, w, f, q, ans;
    ll la, lb, lc, lans;
    string s1, s2;
    char ch1, ch2;
    cin >> t;
    while(t--) {
        cin >> n >> m >> k >> s1;
        fill(arr, arr + n, 0);
        priority_queue<int> tables;
        a = b = c = w = ans = 0;
        for(int i = 0; i < n; i++) {
            if(s1[i] == 'A') {
                if(m) {
                    m--;
                    a++;
                    b += k - 1;
                    if(k > 1) tables.push(1);
                    ans++;
                    cout << i + 1 << " pegou uma nova mesa, m agora eh " << m << " e b = " << b << '\n';
                } else {
                    if(b) {
                        u = tables.top();
                        tables.pop();
                        if(u + 1 < k) tables.push(u + 1);
                        b--;
                        ans++;
                        cout << i + 1 << " pegou uma nova usada, b = " << b << "e m = " << m << '\n';
                    }
                }
            } else if(s1[i] == 'E') {
                if(b) {
                    b--;
                    c++;
                    u = tables.top();
                    tables.pop();
                    if(u + 1 < k) tables.push(u + 1);
                    ans++;
                    cout << i + 1 << " pegou uma nova usada, b = " << b << "e m = " << m << '\n';
                }
            } else w++;
        }
        q = 0;
        while(!tables.empty()) {
            arr[q++] = tables.top();
            tables.pop();
        }
        u = 0;
        v = q - 1;
        int x = 0;
        while(u < v) {
            f = min(k - arr[u], arr[v]);
            arr[u] += f;
            arr[v] -= f;
            if(arr[u] == k) u++;
            if(arr[v] == 0) {
                x++;
                v--;
            }
        }
        ans += min(w, x);
        cout << ans << '\n';
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

#define MAX 212345
#define MAXB 2123456
#define LOG 20
#define PI acos(-1.)
#define MAXG 1123
#define INF 1012345678 // 10^9
#define INFLL 1123456789112345678LL //10^18
#define EPS 1e-9
#define MOD 1000000007
#define MODWPP 998244353
typedef long long ll;
typedef __int128_t i128;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;

int n, m, k, arr[MAXB];
ll vet[MAXB];
bitset<MAX> b1;
vector<vector<int>> graph(MAX);

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int a, b, c, t, u, v, w, f, q, ans;
    ll la, lb, lc, lans;
    string s1, s2;
    char ch1, ch2;
    cin >> t;
    while(t--) {
        cin >> n >> m >> k >> s1;
        fill(arr, arr + n, 0);
        multiset<int> tables;
        a = b = c = w = ans = 0;
        for(int i = 0; i < n; i++) {
            if(s1[i] == 'I') {
                if(m) {
                    ans++;
                    m--;
                    b += k - 1;
                    if(k > 1) tables.insert(1);
                } else {
                    if(c) {
                        tables.erase(tables.find(1));
                        if()
                    }
                }
            } else if(s1[i] == 'E') {
                if(b > 0) {
                    b--;
                    ans++;
                    u = *tables.rbegin();
                    tables.erase(tables.find(u));
                    if(u + 1 < k) tables.insert(u + 1);
                }
            } else {
                if(m) {
                    c++;
                    ans++;
                    m--;
                    b += k - 1;
                    if(k > 1) tables.insert(1);
                } else {
                    if(b) {
                        b--;
                        ans++;
                        u = *tables.rbegin();
                        tables.erase(tables.find(u));
                        if(u == 1) c--;
                        if(u + 1 < k) tables.insert(u + 1);
                    }
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}

class Solution {
public:
    int dp(int i, int j, vector<vector<vector<int>>> &memo, vector<int> &val, vector<vector<int>>& items, int n, int f) {
        if(i == n) return 0;
        if(memo[i][j][f] != -1) return memo[i][j][f];
        int ans = dp(i + 1, j, memo, val, items, n, 0);
        if(j >= items[i][1]) {
            ans = max(ans, dp(i, j - items[i][1], memo, val, items, n, 1) + (f == 0 ? val[i] : 0) + 1);
        }
        return memo[i][j][f] = ans;
    }
    
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = (int) items.size();
        vector<int> cnt(n);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(i == j) continue;
                if(items[j][0] % items[i][0] == 0) cnt[i]++;
            }
        }
        vector<int> dp(budget + 1);
        for(int i = 0; i < n; i++) {
            vector<bool> marked(budget + 1);
            for(int j = items[i][0]; j <= budget; j++) {
                int f = marked[j - items[i][0]]];
                if(dp[j] < dp[j - items[i][0]] + 1 + f * cnt[i]) {
                    dp[j] = dp[j - items[i][0]] + 1 + f * cnt[i];
                    marked[j] = 1;
                }
            }
        }
        return dp[budget];
        vector<vector<vector<int>>> memo(n, vector<vector<int>> (budget + 1, vector<int> (2, -1)));
        return dp(0, budget, memo, cnt, items, n, 0);
    }
}

#include <bits/stdc++.h>
using namespace std;

#define MAX 312345
#define MAXB 2123456
#define LOG 20
#define PI acos(-1.)
#define MAXG 1123
#define INF 1012345678 // 10^9
#define INFLL 1123456789112345678LL //10^18
#define EPS 1e-9
#define MOD 1000000007
#define MODWPP 998244353
typedef long long ll;
typedef __int128_t i128;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;

int n, m, k, arr[MAXB], memo[MAX];
ll vet[MAXB];
bitset<MAX> b1;
vector<vector<int>> graph(MAX);

struct point {
    double x, y;
    point() {}
    point(double _x, double _y) : x(_x), y(_y) {}
};

struct vec {
    double x, y;
    vec() {}
    vec(point a, point b) : x(b.x - a.x), y(b.y - a.y) {}
};

struct circle {
    point cntr; double r;
    circle() {}
    circle(point _cntr, double _r) : cntr(_cntr), r(_r) {}
};

typedef vector<point> vp;

double dot(vec u, vec v) { return u.x * v.x + u.y * v.y; }
double cross(vec u, vec v) { return u.x * v.y - u.y * v.x; }

double dist(point a, point b) {
    vec u(a, b);
    return sqrt(dot(u, u));
}

int in_circle(point a, circle c) {
    return dist(c.cntr, a) + <= c.r + EPS;
}

point get_circle_cntr(vec u, vec v) {
    double uu = dot(u, u), vv = dot(v, v), uxv = cross(u, v);
    return point((v.y * uu - u.y * vv) / (2 * uxv), (u.x * vv - v.x * uu) / (2 * uxv));
}

circle welzl_base(vp r) {
    point cntr, a, b, c;
    if(r.size() == 1) return circle(point(0, 0), 0);
    a = r[0]; b = r[1];
    if(r.size() == 2) cntr = point((a.x + b.x) / 2., (a.y + b.y) / 2.);
    else {
        c = r[2];
        cntr = get_circle_cntr(vec(a, b), vec(a, c));
        cntr.x += a.x; cntr.y += a.y;
    }
    return circle(cntr, dist(cntr, a));
}


circle welzl(vp &p, vp r, int n) {
    if(n == 0 || r.size() == 3) return welzl_base(r);
    circle disk = welzl(p, r, n - 1);
    if(in_circle(p[n - 1], disk)) return disk;
    r.push_back(p[n - 1]);
    return welzl(p, r, n - 1);
}

int dp(int i, int j) {
    if(j == (1 << n) - 1) return 0;
    if(i == m) return INF;
    if(memo[i][j] != -1) return memo[i][j];
    return memo[i][j] = min(dp(i + 1, j), dp(i + 1, j | arr[i]) + 1);
}

//brabo é quem viu aula do zatesko ensinando welzl!

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    srand(time(0));
    int a, b, c, t, u, v, w, f, q, ans;
    ll la, lb, lc, lans;
    string s1, s2;
    char ch1, ch2;
    double r;
    vp p_aux;
    cin >> n >> r;
    for(int i = 0; i < n; i++) {
        cin >> a >> b;
        p_aux.emplace_back((double) a, (double) b);
    }
    m = 0;
    for(int i = 1; i < (1 << n); i++) {
        vp p, r2;
        for(int j = 0; j < n; j++) {
            if(i & (1 << j)) {
                p.push_back(p_aux[j]);
            }
        }
        random_shuffle(p.begin(), p.end());
        circle ans = welzl(p, r2, p.size());
        if(ans.r - EPS < r) arr[m++] = i;
    }
    memset(memo, -1, sizeof(memo));
    cout << dp(0, 0) << '\n';
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

#define MAX 212345
#define MAXB 2123456
#define LOG 20
#define PI acos(-1.)
#define MAXG 1123
#define INF 1012345678 // 10^9
#define INFLL 1123456789112345678LL //10^18
#define EPS 1e-9
#define MOD 1000000007
#define MODWPP 998244353
typedef long long ll;
typedef __int128_t i128;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;

int n, m, k, arr[MAXB];
ll vet[MAXB];
bitset<MAX> b1;
vector<vector<int>> graph(MAX);

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int a, b, c, t, u, v, w, f, q, ans;
    ll la, lb, lc, lans;
    string s1, s2;
    char ch1, ch2;
    cin >> n >> m >> k;
    getline(cin, s1);
    for(int i = 0; i < m; i++) {
        getline(cin, s1);
        s2 = "";
        for(auto c : s1) {
            s2 += string(k, c);
        }
        for(int j = 0; j < k; j++) {
            cout << s2 << '\n';
        }
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

#define MAX 212345
#define MAXB 2123456
#define LOG 20
#define PI acos(-1.)
#define MAXG 1123
#define INF 1012345678 // 10^9
#define INFLL 1123456789112345678LL //10^18
#define EPS 1e-9
#define MOD 1000000007
#define MODWPP 998244353
typedef long long ll;
typedef __int128_t i128;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;

int n, m, k, arr[MAXB];
ll vet[MAXB];
bitset<MAX> b1;
vector<vector<int>> graph(MAX);
set<string> op = {"*", "-", "+", "**", "/"};
map<string, int> prec = {{"*", 1}, {"-", 0}, {"+", 0}, {"**", 2}, {"/", 1}};

vector<string> shuntting_yard(vector<string> &ex) {
    vector<string> answer;
    stack<string> stk;
    for(string s : ex) {
        if(op.count(s) == 1) {
            while(!stk.empty() && stk.top() != "(" && (prec[stk.top()] > prec[s] || (prec[stk.top()] == prec[s] && s != "**"))) {
                answer.push_back(stk.top());
                stk.pop();
            }
            stk.push(s);
        } else if(s == "(") {
            stk.push(s);
        } else if(s == ")") {
            while(stk.top() != "(") {
                answer.push_back(stk.top());
                stk.pop();
            }
            stk.pop();
        } else answer.push_back(s);
    }
    while(!stk.empty()) {
        answer.push_back(stk.top());
        stk.pop();
    }
    return answer;
}

double postfix_exp(vector<string> &ex) {
    stack<string> stk;
    double ans = 0.;
    for(auto s : ex) {
        if(op.count(s) == 0) {
            stk.push(s);
        } else {
            double a = stod(stk.top());
            stk.pop();
            double b = stod(stk.top());
            stk.pop();
            if(s == "+") {
                stk.push(to_string(a + b));
            } else if(s == "-") {
                stk.push(to_string(b - a));
            } else if(s == "*") {
                stk.push(to_string(a * b));
            } else if(s == "/") {
                stk.push(to_string(b / a));
            } else stk.push(to_string(pow(b, a)));
        }
    }
    return stod(stk.top());
}

//cara, que problema eh esse...

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int a, b, c, t, u, v, w, f, q, ans;
    ll la, lb, lc, lans;
    string s1, s2;
    char ch1, ch2;
    vector<string> e1, e2;
    getline(cin, s1);
    cin >> a >> b;
    s2 = "";
    for(auto c : s1) {
        if(c == ' ') {
            if(!s2.empty()) e1.push_back(s2);
            s2 = "";
        } else s2.push_back(c);
    }
    e1.push_back(")");
    stack<char> stk;
    w = 10000;
    double step = (double) (b - a) / (double) w;
    double area = 0.;
    for(int i = 0; i < w; i++) {
        double s = (double) a + ((double) i + 0.5) * step;
        e2 = e1;
        for(string &str : e2) {
            if(str == "x") str = to_string(s);
        }
        vector<string> ex = shuntting_yard(e2);
        double y = postfix_exp(ex);
        area += y * step;
    }
    cout << fixed;
    cout.precision(1);
    cout << area << '\n';
    return 0;
}

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
ll x, y, vet[MAXB], dp[MAX][2];
bitset<MAX> b1;
vector<vector<int>> graph(MAX);
string s;

void dfs(int u) {
    for(int v : graph[u]) {
        if(v != n) dfs(v);
    }
    if(arr[u] != -1) {
        dp[u][arr[u]] = 1ll;
    } else {
        int v = graph[u][0];
        int w = graph[u][1];
        dp[u][0] = (dp[v][0] * dp[w][1] % MOD + dp[v][1] * (dp[w][0] + dp[w][1]) % MOD) % MOD;
        dp[u][1] = dp[v][1] * dp[w][1] % MOD;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int a, b, c, t, u, v, w, f, q, ans;
    ll la, lb, lc, lans;
    string s1, s2;
    char ch1, ch2;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> u >> v >> f;
        u--; v--;
        graph[i].push_back(u == -1 ? n : u);
        graph[i].push_back(v == -1 ? n : v);
        arr[i] = f;
    }
    dp[n][0] = dp[n][1] = 1ll;
    dfs(0);
    cout << (dp[0][0] + dp[0][1]) % MOD << '\n';
    return 0;
}

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
vector<vector<int>> graph(MAX);
string s;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int a, b, c, t, u, v, w, f, q, ans;
    ll la, lb, lc, lans;
    string s1, s2;
    char ch1, ch2;
    vector<pii> pxpy, pxny, nxpy, nxny;
    cin >> n;
    ans = 0;
    for(int i = 0; i < n; i++) {
        cin >> a >> b;
        if(a >= 0) {
            if(b >= 0) pxpy.emplace_back(a, b);
            else pxny.emplace_back(a, b);
        } else {
            if(b >= 0) nxpy.emplace_back(a, b);
            else nxny.emplace_back(a, b);
        }
    }
    sort(pxpy.begin(), pxpy.end());
    sort(pxny.begin(), pxny.end());
    sort(nxpy.begin(), nxpy.end());
    sort(nxny.begin(), nxny.end());
    a = 0;
    for(int i = (int) pxpy.size(); i >= 0; i--) {
        if(i == (int) pxpy.size() && i != 0 && pxpy[i - 1].second == 0) continue;
        c = i == (int) pxpy.size() ? 0 : pxpy[i].second;
        while(a < (int) nxny.size() && abs(nxny[a].second) <= c) a++;
        ans = max(ans, (int) pxny.size() + (int) nxpy.size() + i + ((int) nxny.size() - a));
    }
    a = 0;
    for(int i = (int) nxpy.size(); i >= 0; i--) {
        if(i == (int) nxpy.size() && i != 0 && nxpy[i - 1].)
    }
    return 0;
}

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
vector<vector<int>> graph(MAX);
string s;

struct point {
    ll x, y;
    point() {}
    point(ll _x, ll _y) : x(_x), y(_y) {}
};

struct vec {
    ll x, y;
    vec() {}
    vec(ll _x, ll _y) : x(_x), y(_y) {}
    vec(point a, point b) : x(b.x - a.x), y(b.y - a.y) {}
};

ll cross(vec u, vec v) {
    return u.x * v.y - u.y * v.x;
}

bool comp(const vec &u, const vec &v) {
    return cross(u, v) > 0ll;
} 

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int a, b, c, t, u, v, w, f, q, ans;
    ll la, lb, lc, lans;
    string s1, s2;
    char ch1, ch2;
    cin >> t;
    while(t--) {
        vector<vec> py, ny;
        cin >> n;
        for(int i = 0; i < n; i++) {
            cin >> a >> b;
            if(b >= 0) py.push_back(vec(a, b));
            else ny.push_back(vec(a, b));
        }
        sort(py.begin(), py.end(), comp);
        sort(ny.begin(), ny.end(), comp);
        vector<pair<vec, int>> vpy, vny;
        for(vec u : py) {
            if(vpy.empty() || cross(u, vpy.back().first) != 0ll) {
                vpy.emplace_back(u, 1);
            } else vpy.back().second++;
        }
        for(vec u : ny) {
            if(vny.empty() || cross(u, vny.back().first) != 0ll) {
                vny.emplace_back(u, 1);
            } else vny.back().second++;
        }
        ans = 0;
        a = 0;
        b = c = 0;
        for(int i = (int) vpy.size(); i >= 0; i--) {
            if(i == (int) vpy.size() && i > 0 && vpy[i - 1].first.y == 0ll) continue;
            vec aux = i == (int) vpy.size() ? vec(1ll, 0ll) : vpy[i].first;
            if(i != (int) vpy.size()) c += vpy[i].second;
            while(a < (int) vny.size() && cross(vny[a].first, aux) >= 0ll) {
                b += vny[a].second;
                a++;
            }
            ans = max(ans, max((int) py.size() + (int) ny.size() - b - c, b + c));
        }
        cout << ans << '\n';
    }
    return 0;
}