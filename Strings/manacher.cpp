void manacher(const string& s, vector<int>& d1, vector<int>& d2) {
    int n = (int)s.size();
    d1.assign(n, 0);
    int l = 0, r = -1;
    for(int i = 0; i < n; ++i) {
        int k = 1;
        if(i <= r) k = min(d1[l + r - i], r - i + 1);
        while (i - k >= 0 && i + k < n && s[i - k] == s[i + k]) ++k;
        d1[i] = k;
        if(i + k - 1 > r) { l = i - k + 1; r = i + k - 1; }
    }
    d2.assign(n, 0);
    l = 0; r = -1;
    for(int i = 0; i < n; ++i) {
        int k = 0;
        if(i <= r) k = min(d2[l + r - i + 1], r - i + 1);
        while(i - k - 1 >= 0 && i + k < n && s[i - k - 1] == s[i + k]) ++k;
        d2[i] = k;
        if(i + k - 1 > r) { l = i - k; r = i + k - 1; }
    }
}

pair<int, pair<int,int>> longest_pal(const string& s) {
    vector<int> d1, d2;
    manacher(s, d1, d2);
    int n = (int)s.size(), best = 0, L = 0, R = -1;
    for(int i = 0; i < n; ++i) {
        int len = 2 * d1[i] - 1;
        if (len > best) { best = len; L = i - d1[i] + 1; R = i + d1[i] - 1; }
    }
    for(int i = 0; i < n; ++i) {
        int len = 2 * d2[i];
        if(len > best) { best = len; L = i - d2[i]; R = i + d2[i] - 1; }
    }
    return {best, {L, R}};
}

long long count_pal(const string& s) {
    vector<int> d1, d2;
    manacher(s, d1, d2);
    long long ans = 0;
    for(int x : d1) ans += x;
    for(int x : d2) ans += x;
    return ans;
}
