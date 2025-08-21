// dada uma sting contento apenas caracteres '(' e ')', encontra
// qual o tamanho da maior substring de parenteses validos, e quantas strings
// desse tamanho (não necessariamente iguais) existem

#include <bits/stdc++.h>
using namespace std;

#define MAX 1123456
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

#define left(u) ((u) + 1)
#define right(u, m, l) ((u) + 2 * ((m) - (l) + 1))

int st[2 * MAX];

int build_st(int u, int l, int r) {
    if(l == r) return st[u] = arr[l];
    int m = (l + r) / 2;
    return st[u] = min(build_st(left(u), l, m), build_st(right(u, m, l), m + 1, r));
}

int search_min(int u, int l, int r, int i, int j, int val) {
    if(r < i || l > j || st[u] >= val) return n;
    if(l == r) {
        if(arr[l] < val) return l;
    }
    int m = (l + r) / 2;
    int lft = search_min(left(u), l, m, i, j, val);
    if(lft < n) return lft;
    else return search_min(right(u, m, l), m + 1, r, i, j, val);
}

int search_zero(int u, int l, int r, int i, int j, int val) {
    if(r < i || l > j || st[u] > val) return -1;
    if(l == r) {
        if(arr[l] == val) return l;
    }
    int m = (l + r) / 2;
    int rgt = search_zero(right(u, m, l), m + 1, r, i, j, val);
    if(rgt > -1) return rgt;
    else return search_zero(left(u), l, m, i, j, val);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int a, b, c, t, u, v, w, f, q, ans;
	ll la, lb, lc, lans;
    string s1, s2;
    char ch1, ch2;
    cin >> s1;
    a = 0;
    n = s1.size();
    for(int i = 0; i < n; i++) {
        if(s1[i] == '(') a++;
        else a--;
        arr[i] = a;
    }
    ans = 0, c = 1;
    build_st(0, 0, n - 1);
    for(int i = 0; i < n; i++) {
        if(s1[i] == '(') {
            int j = search_min(0, 0, n - 1, i + 1, n - 1, arr[i] - 1);
            int k = search_zero(0, 0, n - 1, i + 1, j - 1, arr[i] - 1);
            if(k > i) {
                if(k - i + 1 > ans) {
                    ans = k - i + 1;
                    c = 1;
                } else if(k - i + 1 == ans) c++;
            }
        }
    }
    cout << ans << ' ' << c << '\n';
    return 0;
}