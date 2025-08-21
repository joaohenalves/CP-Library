string pat, tex;
int table[MAX]; // max size of string p;

void kmpPre() {
    int i = 0, j = -1;
    table[0] = -1;
    while(i < m) {
        while(j >= 0 && pat[i] != pat[j]) j = table[j];
        table[++i] = ++j;
    }
}

int kmp() {
    int ans = 0, i = 0, j = 0;
    kmpPre();
    while(i < n) {
        while(j >= 0 && tex[i] != pat[j]) j = table[j];
        i++; j++;
        if(j == m) ans++;
    }
    return ans;
}