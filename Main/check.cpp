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

int n, m, k, arr[MAX];
ll vet[MAX];
bitset<MAX> b1;
vector<vector<int>> graph(MAX);

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int a, b, c, t, u, v, w, f, q, ans;
    ll la, lb, lc, lans;
    string s1, s2;
    char ch1, ch2;
    vector<ll> res1;
    freopen("output.txt", "r", stdin);
    for(int i = 0; i <= 100; i++) {
        for(int j = 1; j <= 20; j++) {
            cin >> la;
            res1.push_back(la);
        }
    }
    freopen("correct.txt", "r", stdin);
    a = 0;
    for(int i = 0; i <= 100; i++) {
        for(int j = 1; j <= 20; j++) {
            cin >> la;
            if(res1[a] != la) {
                cout << i << ' ' << j << ' ' << res1[a] << ' ' << la << '\n';
            }
            a++;
        }
    }
    return 0;
}