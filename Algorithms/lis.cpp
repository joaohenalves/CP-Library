int l[MAXB], id[MAXB], prv[MAXB], ls[MAXB];

int lis() {
    int s = 0;
    for(int i = 0; i < n; i++) {
        int it = lower_bound(l, l + s, arr[i]) - l;
        prv[i] = (it == 0 ? -1 : id[it - 1]);
        l[it] = arr[i];
        id[it] = i;
        if(it == s) s++;
    }
    return s;
}

void getAns() {
    int u, ans = lis();
    u = id[ans - 1];
    k = 0;
    while(u >= 0) {
        ls[k++] = u;
        u = prv[u];
    }
    reverse(ls, ls + k);
}