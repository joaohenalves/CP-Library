#define to_i(ch) ((ch) >= 'a' ? (ch) - 'a' + 26 : (ch) - 'A')
#define ALPHASIZE 52

struct node {
    int nxt[ALPHASIZE], term = 0, p, pc, link = -1, go[ALPHASIZE], ext = -1, occ = 0;
    vector<int> idx;
    node(int _p = 0, int _pc = 0) : p(_p), pc(_pc) {
        memset(nxt, -1, sizeof(nxt));
        memset(go, -1, sizeof(go));
    }
};

vector<node> aca; //aho-corasick automaton
int occ[MAX]; //every word in the dict

void ins(const string &s, int idx) {
    int u = 0;
    for(int i = 0; i < s.size(); i++) {
        int c = to_i(s[i]);
        if(aca[u].nxt[c] == -1) {
            aca[u].nxt[c] = aca.size();
            aca.emplace_back(u, c);
        }
        u = aca[u].nxt[c];
    }
    aca[u].term = 1;
    aca[u].idx.push_back(idx);
}

int go(int u, int c);

int link(int u) {
    if(aca[u].link != -1) return aca[u].link;
    return aca[u].link = (u == 0 || aca[u].p == 0) ? 0 : 
        go(link(aca[u].p), aca[u].pc);
}

int ext(int u) { //assumes u != 0
    int v = link(u);
    if(aca[u].ext != -1) return aca[u].ext;
    return aca[u].ext = (v == 0 || aca[v].term) ? v : ext(v);
}

int go(int u, int c) {
    if(aca[u].go[c] != -1) return aca[u].go[c];
    if(aca[u].nxt[c] != -1) return aca[u].go[c] = aca[u].nxt[c];
    return aca[u].go[c] = u == 0 ? 0 : go(link(u), c); 
}

void process(const string &t) {
    int u = 0;
    for(int i = 0; i < t.size(); i++) {
        int c = to_i(t[i]);
        u = go(u, c);
        for(int v = u; v; v = ext(v)) {
            aca[v].occ++;
        }
    }
    for(u = 0; u < (int) aca.size(); u++) {
        for(auto &idx : aca[u].idx) {
            occ[idx] += aca[u].occ;
        }
    }
}

void init() {
    aca.clear();
    aca.emplace_back();
    fill(occ, occ + n, 0);
    string t, s;
    ins(s, i); // strings to be inserted(i = index 0 ~ queries-1);
    process(t); // string to be searched upon
    occ[i]; // occurances of pattern s in text t
}