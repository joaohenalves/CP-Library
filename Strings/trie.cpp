#define to_i(ch) ((ch) >= 'a' ? (ch) - 'a' + 26 : (ch) - 'A')

struct node {
    int nxt[52], term = 0, occ = 0, l = 0;
    node() {memset(nxt, -1, sizeof(nxt));}
};

vector<node> trie;

void ins(string &s) {
    int c1, u = 0;
    for(auto c : s) {
        c1 = to_i(c);
        if(trie[u].nxt[c1] == -1) {
            trie[u].l++;
            trie[u].nxt[c1] = trie.size();
            trie.emplace_back();
        }
        u = trie[u].nxt[c1];
        trie[u].occ++;
    }
    trie[u].term = 1;
}