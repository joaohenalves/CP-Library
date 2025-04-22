#include <bits/stdc++.h>
using namespace std;

#define MAX 212345
#define LOG 20
#define PI acos(-1.)
#define MAXG 1123
#define INF 1123456789
#define MOD 1000000007
#define INFLL 112345678911234567
#define EPS 1e-9
typedef long long ll;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;

int n, m, arr[MAX], mat1[MAXG][MAXG];
ll vet[MAX];
bitset<MAX> b1;
vector<vector<int>> graph(MAX);

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
    freopen("../Main/output.txt", "r", stdin);
	int a, b, c, d, f, t, q, ans;
    string s1, s2;
    ll la, lb, lc;
    char ch1, ch2;
    for(int i = 0; i < 1000; i++) {
        for(int j = 0; j < 5; j++) {
            cin >> mat1[i][j];
        }
    }
    freopen("outcorrect.txt", "r", stdin);
    for(int i = 0; i < 1000; i++) {
        f = 0;
        for(int j = 0; j < 5; j++) {
            cin >> a;
            if(a != mat1[i][j]) f = 1;
        }
        if(f) cout << "Deu errado no caso " << i << '\n';
    }
    return 0;
}