#include <bits/stdc++.h>
using namespace std;

#define MAX 112345
#define MAXS 1123
typedef long long ll;
typedef pair<int, int> pii;
typedef tuple<ll, ll, int> tlli;
const ll MOD = 1000000007;

int n, m, arr[MAX], parent[MAX], nodeRank[MAX], tsize[MAX], vis[MAX];
ll pref[MAX];
vector<vector<int>> graph(MAX);

int findSet(int u) {
    if(parent[u] == u) return u;
    return parent[u] = findSet(parent[u]);
}

void unionSets(int u, int v) {
    u = findSet(u);
    v = findSet(v);
    if(nodeRank[v] < nodeRank[u]) {
        parent[v] = u;
    } else {
        parent[u] = v;
        if(nodeRank[u] == nodeRank[v]) nodeRank[v]++;
    }
}

void dfs(int u, int p) {
    vis[u] = 1;
    m++;
    for(int &v : graph[u]) {
        if(vis[v] == 1 && v != p) {
            cout << "Has cycles!\n";
            exit(0);
        }
        if(v != p) {
            dfs(v, u);
            tsize[u] += tsize[v];
        }
    }
    tsize[u]++;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("../Main/input.txt", "w", stdout);
    int flag;
    ll t, d;
    int u, v, q;
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> num1(1,1000000000);
    std::uniform_int_distribution<std::mt19937::result_type> vn1(1,100000);
    cout << 4 << '\n';
    for(int cases = 0; cases < 4; cases++) {
        memset(nodeRank, 0, sizeof(nodeRank));
        memset(vis, 0, sizeof(vis));
        memset(tsize, 0, sizeof(tsize));
        n = 100000;
        q = 100000;
        iota(parent, parent + n + 1, 0);
        cout << n << ' ' << q << '\n';
        for(int i = 0; i < n; i++) {
            cout << num1(rng) << (i == n - 1 ? '\n' : ' ');
        }
        std::uniform_int_distribution<std::mt19937::result_type> vert1(1,n);
        for(int i = 0; i < 100000000; i++) {
            u = vert1(rng);
            v = vert1(rng);
            if(findSet(u) != findSet(v)) {
                unionSets(u, v);
                graph[u].push_back(v);
                graph[v].push_back(u);
                cout << u << ' ' << v << '\n';
            }
        }
        for(int i = 2; i <= n; i++) {
            if(findSet(1) != findSet(i)) {
                unionSets(1, i);
                cout << 1 << ' ' << i << '\n';
            }
        }
        m = 0;
        dfs(1, -1);
        if(m != n) cout << "Not a tree!\n";
        for(int i = 0; i < q; i++) {
            int u = vert1(rng);
            std::uniform_int_distribution<std::mt19937::result_type> dist4(1,tsize[u]);
            cout << u << ' ' << dist4(rng) << '\n';
        }
        for(int i = 0; i < MAX; i++) graph[i].clear();
    }
    return 0;
}