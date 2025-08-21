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