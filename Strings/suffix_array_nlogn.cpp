#define _ra(i) ((i) < n ? ra[i] : 0)

int owner[MAX], sa[MAX], tempsa[MAX], lcp[MAX], ra[MAX], tempra[MAX], phi[MAX], plcp[MAX];
string s;

void counting_sort(int kk) {
    int maxi = max(300, n);
    static int c[MAX];
    for(int i = 0; i < maxi; i++) c[i] = 0;
    for(int i = 0; i < n; i++) {
        c[_ra(i + kk)]++;
    }
    int sum = 0;
    for(int i = 0; i < maxi; i++) {
        int t = c[i];
        c[i] = sum;
        sum += t;
    }
    for(int i = 0; i < n; i++) {
        int key = _ra(sa[i] + kk);
        tempsa[c[key]++] = sa[i];
    }
    for(int i = 0; i < n; i++) {
        sa[i] = tempsa[i];
    }
}

void compute_lcp() {
    phi[sa[0]] = -1;
    for(int i = 1; i < n; i++) phi[sa[i]] = sa[i - 1];
    for(int i = 0, l = 0; i < n; i++) {
        if(phi[i] == -1) {
            plcp[i] = 0;
            continue;
        }
        while(s[i + l] == s[phi[i] + l]) l++;
        plcp[i] = l--;
        l = max(0, l);
    }
    for(int i = 0; i < n; i++) {
        lcp[i] = plcp[sa[i]];
    }
}

void build_sa() {
    int r;
    for(int i = 0; i < n; i++) {
        sa[i] = i;
        ra[i] = s[i];
    }
    for(k = 1; k < n; k <<= 1) {
        counting_sort(k);
        counting_sort(0);
        tempra[sa[0]] = r = 0;
        for(int i = 1; i < n; i++) {
            tempra[sa[i]] = ra[sa[i]] == ra[sa[i - 1]] &&
                _ra(sa[i] + k) == _ra(sa[i - 1] + k) ? r : ++r;
        }
        for(int i = 0; i < n; i++) ra[i] = tempra[i];
        if(ra[sa[n - 1]] == n - 1) break;
    }
}

void suffix_array(string &a, string &b) {
    s = a + "$" + b + "#";
    n = (int) s.size();
    for(int i = 0;  i < n; i++) {
        owner[i] = i > (int) a.size();
    }
    build_sa();
    compute_lcp();
}

int max_common_substr() {
    int ans = 0;
    for(int i = 1; i < n; i++) {
        if(owner[sa[i]] != owner[sa[i - 1]]) {
            ans = max(ans, lcp[i]);
        }
    }
    return ans;
}