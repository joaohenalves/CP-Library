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

int n, m, k, d, arr[MAXB], g1[MAXG][MAXG];
ll vet[MAXB];
bitset<MAX> b1;
vector<vector<int>> graph(MAX);
vector<string> c1(MAXG);
vector<vector<pii>> org(MAXG, vector<pii> (MAXG));
char c2[MAXG][MAXG];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int a, b, c, t, u, v, w, f, q, ans;
    ll la, lb, lc, lans;
    string s1, s2;
    char ch1, ch2;
    memset(c2, 'Z' + 1, sizeof(c2));
    cin >> n >> m;
    d = n + m - 1;
    for(int i = 0; i < n; i++) {
        cin >> c1[i];
        for(int j = 0; j < m; j++) {
            c2[i - j + m - 1][i + j] = c1[i][j];
        }
    }
    cin >> a;
    vector<vector<int>> dic(a, vector<int> (27));
    for(int i = 0; i < a; i++) {
        cin >> s1;
        for(char ch : s1) {
            dic[i][ch - 'A']++;
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            org[i - j + m - 1][i + j] = {i, j};
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            vector<int> aux(27);
            for(int k = j; k < m; k++) {
                aux[c1[i][k] - 'A']++;
                for(int l = 0; l < a; l++) {
                    if(aux == dic[l]) {
                        for(int o = j; o <= k; o++) {
                            g1[i][o] |= (1 << l);
                        }
                    }
                }
            }
        }
    }
    for(int j = 0; j < m; j++) {
        for(int i = 0; i < n; i++) {
            vector<int> aux(27);
            for(int k = i; k < n; k++) {
                aux[c1[k][j] - 'A']++;
                for(int l = 0; l < a; l++) {
                    if(aux == dic[l]) {
                        for(int o = i; o <= k; o++) {
                            g1[o][j] |= (1 << l);
                        }
                    }
                }
            }
        }
    }
    for(int i = 0; i < d; i++) {
        for(int j = 0; j < d; j++) {
            vector<int> aux(27);
            for(int k = j; k < d; k++) {
                aux[c2[i][k] - 'A']++;
                for(int l = 0; l < a; l++) {
                    if(aux == dic[l]) {
                        for(int o = j; o <= k; o++) {
                            auto [u, v] = org[i][o];
                            g1[u][v] |= (1 << l);
                        }
                    }
                }
            }
        }
    }
    for(int j = 0; j < d; j++) {
        for(int i = 0; i < d; i++) {
            vector<int> aux(27);
            for(int k = i; k < d; k++) {
                aux[c2[k][j] - 'A']++;
                for(int l = 0; l < a; l++) {
                    if(aux == dic[l]) {
                        for(int o = i; o <= k; o++) {
                            auto [u, v] = org[o][j];
                            g1[u][v] |= (1 << l);
                        }
                    }
                }
            }
        }
    }
    ans = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(__builtin_popcount(g1[i][j]) > 1) ans++;
        }
    }
    cout << ans << '\n';
    return 0;
}