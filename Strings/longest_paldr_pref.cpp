void lps(string str) {
    string temp = str + '?';
    reverse(str.begin(), str.end());
    temp += str;
    int n = temp.length();
    vector<int> lp(n);
    for(int i = 1; i < n; i++) {
        int len = lp[i - 1];
        while(len > 0 && temp[len] != temp[i]) {
            len = lp[len - 1];
        }
        if(temp[i] == temp[len]) {
            len++;
        }
        lp[i] = len;
    }
    cout << temp.substr(0, lp[n - 1]);
}