//Radix Trie do Gepeto, não testei isso

#define to_i(ch) ((ch)-'a')

struct node {
    int nxt[26], occ, term;
    string st;
    node(): occ(0), term(0), st("") { memset(nxt, -1, sizeof(nxt)); }
    node(string z): occ(0), term(0), st(z) { memset(nxt, -1, sizeof(nxt)); }
};

vector<node> trie;

void init_trie() {
    trie.clear();
    trie.emplace_back(""); 
}

int match(const string &s, const string &e, int c) {
    int k = 0, n = (int)s.size(), m = (int)e.size();
    while (k < m && c + k < n && s[c + k] == e[k]) ++k;
    return k;
}

void ins(const string &s) {
    int u = 0, i = 0;
    trie[u].occ++;
    while (i < (int)s.size()) {
        int c = to_i(s[i]);
        if (trie[u].nxt[c] == -1) {
            trie[u].nxt[c] = (int)trie.size();
            trie.emplace_back(s.substr(i));
            trie.back().term = 1;
            trie.back().occ = 1;
            return;
        }
        u = trie[u].nxt[c];
        trie[u].occ++;
        int x = match(s, trie[u].st, i);
        if (x < (int)trie[u].st.size()) {
            int old = trie[u].occ - 1;
            int last = (int)trie.size();
            trie.emplace_back(trie[u].st.substr(x));
            trie[last].term = trie[u].term;
            trie[last].occ  = old;
            memcpy(trie[last].nxt, trie[u].nxt, sizeof(trie[u].nxt));
            memset(trie[u].nxt, -1, sizeof(trie[u].nxt));
            trie[u].st.resize(x);
            trie[u].nxt[to_i(trie[last].st[0])] = last;
            trie[u].term = (i + x == (int)s.size());
            if (i + x == (int)s.size()) return;
            i += x;
            continue;
        }
        i += x;
        if (i == (int)s.size()) { trie[u].term = 1; return; }
    }
}

int count_prefix(const string &s) {
    int u = 0, i = 0;
    while (i < (int)s.size()) {
        int x = match(s, trie[u].st, i);
        if (i + x == (int)s.size()) return trie[u].occ;     // prefixo termina aqui (mesmo no meio da aresta)
        if (x < (int)trie[u].st.size()) return 0;           // quebrou no meio sem terminar o prefixo
        i += x;
        int c = to_i(s[i]);
        if (trie[u].nxt[c] == -1) return 0;
        u = trie[u].nxt[c];
    }
    return trie[u].occ;
}

bool exists_word(const string &s) {
    int u = 0, i = 0;
    while (i < (int)s.size()) {
        int x = match(s, trie[u].st, i);
        if (x < (int)trie[u].st.size()) return false;
        i += x;
        if (i == (int)s.size()) return trie[u].term;
        int c = to_i(s[i]);
        if (trie[u].nxt[c] == -1) return false;
        u = trie[u].nxt[c];
    }
    return false;
}
