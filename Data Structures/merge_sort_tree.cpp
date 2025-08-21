// build: O(n log (n))
// não esquecer de usar multiset ao invés de set, se tiver que fazer algo que suporte updates

#define lft(u) ((u) << 1)
#define rgt(u) (lft(u) + 1)

vector<int> st[2 * MAX];

void build() {
    for(int i = n; i < (n << 1); i++) {
        st[i] = {arr[i - n]};
    }
    for(int i = n - 1; i > 0; i--) {
        merge(st[lft(i)].begin(), st[lft(i)].end(),
              st[rgt(i)].begin(), st[rgt(i)].end(),
              back_inserter(st[i])
        );
    }
}

// conta quantos números entre x e y, inclusive, existem no intervalo [l, r]
int countRange(int l, int r, int x, int y) {
    int ans = 0;
    for(l += n, r += n; l <= r; ++l >>= 1, --r >>= 1) {
        if((l & 1) == 1) ans += upper_bound(st[l].begin(), st[l].end(), y) - lower_bound(st[l].begin(), st[l].end(), x);
        if((r & 1) == 0) ans += upper_bound(st[r].begin(), st[r].end(), y) - lower_bound(st[r].begin(), st[r].end(), x);
    }
    return ans;
}

// retorna qual o menor elemento maior ou igual a x dentro de [l, r]
int minGteX(int l, int r, int x) {
    int ans = INF;
    for(l += n, r += n; l <= r; ++l >>= 1, --r >>= 1) {
        if((l & 1) == 1) {
            auto it1 = lower_bound(st[l].begin(), st[l].end(), x);
            if(it1 != st[l].end()) ans = min(ans, *it1);
        }
        if((r & 1) == 0) {
            auto it2 = lower_bound(st[r].begin(), st[r].end(), x);
            if(it2 != st[r].end()) ans = min(ans, *it2);
        }
    }
    return ans;
}

