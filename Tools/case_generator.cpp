#include <bits/stdc++.h>
using namespace std;

#define MAX 212345
#define MAXG 1123
#define INF 1123456789
#define INFLL 112345678911234567
#define EPS 1e-9
typedef long long ll;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;

int n, m, arr[MAX], grid[MAXG][MAXG];
ll pref[MAX];
vector<set<int>> graph(MAX);
vector<pii> ans;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
    freopen("input.txt", "w", stdout);
	for(int i = 0; i < 1000; i++) {
        cout << 5 << '\n';

        std::random_device rd;  // Seed source
        std::mt19937 gen(rd()); // Mersenne Twister engine
        // Define the distribution range [l, r]
        std::uniform_int_distribution<> dist(1, 20);
        for(int i = 0; i < 5; i++) {
            for(int j = 0; j < 5; j++) {
                int random_number = dist(gen);
                std::cout << random_number << ' ';
            }
            cout << '\n';
        }
    }
    return 0;
}
