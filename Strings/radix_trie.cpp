// Não sei se tá certo de verdade isso, principalmente a parte de contagem dos prefixos (occ)
// temqueverissoae

#define to_i(ch) ((ch) - 'a')

struct node {
    int nxt[26], occ = 0, term = 0;
    string st;
    node() {memset(nxt, -1, sizeof(nxt));}
    node(string z) {memset(nxt, -1, sizeof(nxt)); st = z;}
};

vector<node> trie;

int match(string &s1, string &s2, int c) {
    int ans = 0;
    for(int i = 0; i < min(s2.size(), s1.size() - c); i++) {
        if(s1[i + c] == s2[i]) ans++;
        else break;
    }
    return ans;
}

void ins(string &s) {
    int u = 0, i = 0, x, c, last;
    trie[u].occ++;
    while(i < s.size()) {
        c = to_i(s[i]);
        if(trie[u].nxt[c] == -1) {
            trie[u].nxt[c] = trie.size();
            trie.emplace_back(s.substr(i));
            trie.back().term = 1;
            trie.back().occ = 1;
            return;
        }
        u = trie[u].nxt[c];
        trie[u].occ++;
        x = match(s, trie[u].st, i);
        if(x < trie[u].st.size()) {
            int old = trie[u].occ - 1;
            last = trie.size();
            trie.emplace_back(trie[u].st.substr(x));
            trie[last].term = trie[u].term;
            trie[last].occ = old;
            memcpy(trie[last].nxt, trie[u].nxt, sizeof(trie[u].nxt));
            memset(trie[u].nxt, -1, sizeof(trie[u].nxt));
            trie[u].st = trie[u].st.substr(0, x);
            trie[u].nxt[to_i(trie[last].st[0])] = last;
            trie[u].term = i + x == s.size();
        }
        if(i + x == s.size()) {
            trie[u].term = 1;
            return;
        }
        i += x;
    }
}

void search(string &s) {
    int u = 0, i = 0, x;
    while(i < s.size()) {
        x = match(s, trie[u].st, i);
        if(x == trie[u].st.size()) {
            i += x;
            if(trie[u].term == 1) {
                // Uma (ou mais) string com prefixo de tamanho i
                // em comum com s existe na trie
            }
            if(i < s.size() && trie[u].nxt[to_i(s[i])] != -1) {
                u = trie[u].nxt[to_i(s[i])];
            } else return;
        } else return;
    }
}