//https://atcoder.jp/contests/abc451/tasks/abc451_f

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

int n, m, k, c1, c2, arr[MAXB], vis[MAX];
ll vet[MAXB];
bitset<MAX> b1;
vector<vector<int>> graph(MAX);
vector<pii> edges;
vector<map<int, int>> color(MAX);

void dfs(int u, int c) {
    if(k == 0) return;
    vis[u] = c;
    for(int v : graph[u]) {
        if(vis[u] == vis[v]) {
            k = 0;
            return;
        } else dfs(v, c ^ 1);
    }
}

bool check(int guess) {
    for(int i = 0; i < n; i++) {
        graph[i].clear();
        vis[i] = -1;
    }
    for(int i = 0; i < guess; i++) {
        auto [u, v] = edges[i];
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    k = 1;
    for(int i = 0; i < n; i++) {
        if(vis[i] == 0) dfs(i, 0);
    }
    return k;
}

int binSearch(int inf, int sup) {
    int mid;
    while(inf < sup) {
        mid = inf + (sup - inf + 1) / 2;
        if(check(mid) == true) inf = mid;
        else sup = mid - 1;
    }
    return inf;
}

int parent[MAX], nodeRank[MAX];

int findSet(int u) {
    if(parent[u] == u) return u;
    return parent[u] = findSet(parent[u]);
}

void merge(int u, int v, int colorU, int colorV) {
    if((int) color[u].size() < (int) color[v].size()) {
        color[u].swap(color[v]);
    }
    int f = 0;
    if(colorU == colorV) f = 1;
    for(auto [w, c] : color[v]) {
        color[u][w] = c ^ f;
        if((c ^ f) == 1) c2++;
        else c2--;
    }
}

void unionSets(int u, int v) {
    int colorU = color[findSet(u)][u];
    int colorV = color[findSet(v)][v];
    u = findSet(u);
    v = findSet(v);
    if(nodeRank[u] > nodeRank[v]) {
        parent[v] = u;
        merge(u, v, colorU, colorV);
    } else {
        parent[u] = v;
        if(nodeRank[v] == nodeRank[u]) nodeRank[v]++;
        merge(v, u, colorV, colorU);
    }
}

void preprocess() {
    fill(nodeRank, nodeRank + n, 0);
    iota(parent, parent + n, 0);
    for(int i = 0; i < n; i++) {
        color[i][i] = 0;
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
    for(int i = 0; i < q; i++) {
        cin >> u >> v;
        u--; v--;
        edges.emplace_back(u, v);
    }
    u = binSearch(0, q);
    preprocess();
    for(int i = 0; i < q; i++) {
        if(i >= u) cout << -1 << '\n';
        else {
            auto [u, v] = edges[i];
            if(findSet(u) != findSet(v)) {
                unionSets(u, v);
            }
            cout << c2 << '\n';
        }
    }
    return 0;
}