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
    cin >> t;
    while(t--) {
        cin >> n;
        ans = 0;
        for(int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cout << ans << '\n';
    }
    return 0;
}