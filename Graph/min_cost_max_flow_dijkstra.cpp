// passar o parametro f = 1 no setEdge se o grafo nao for dirigido
// detalhe mindblowing: se todos os custos iniciais das arestas
// sao nao-negativos (sem contar as arestas reversas com -cap), nao
// precisa nem usar o spfa! da soh pra comecar o array pot com tudo 0LL
// referencia pra essa afirmacao: https://web.stanford.edu/class/cs361b/files/cs361b-notes.pdf
// (deve estar em algum lugar desse pdf essa afirmacao lol)

typedef pair<ll, ll> pll;
int inQueue[MAX], start[MAX], parent[MAX];
ll prio[MAX], pot[MAX];

struct edge {
    int u, v, nxt;
    ll cap, cost;
    edge() {}
    edge(int _u, int _v, int _nxt, ll _cap, ll _cost) :
        u(_u), v(_v), nxt(_nxt), cap(_cap), cost(_cost) {}
};

vector<edge> eg;

void spfa(int s) {
    fill(pot, pot + n, INFLL);
    memset(inQueue, 0, sizeof(inQueue));
    queue<int> q;
    pot[s] = 0LL;
    inQueue[s] = 1;
    q.push(s);
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        inQueue[u] = 0;
        for(int i = start[u]; i != -1; i = eg[i].nxt) {
            int v = eg[i].v;
            if(eg[i].cap > 0LL && pot[v] > pot[u] + eg[i].cost) {
                pot[v] = pot[u] + eg[i].cost;
                if(inQueue[v] == 0) {
                    inQueue[v] = 1;
                    q.push(v);
                }
            }
        }
    }
}

ll dijkstra(int s, int t) {
    // retorna o bneck, ou 0 se nenhum caminho foi encontrado
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    fill(prio, prio + n, INFLL);
    fill(parent, parent + n, -1);
    prio[s] = 0LL;
    pq.emplace(0LL, s);
    while(!pq.empty()) {
        auto [du, u] = pq.top();
        pq.pop();
        if(prio[u] < du) continue;
        for(int i = start[u]; i != -1; i = eg[i].nxt) {
            int v = eg[i].v;
            if(eg[i].cap > 0LL &&
               prio[v] > du + eg[i].cost + pot[u] - pot[v]) {
                prio[v] = du + eg[i].cost + pot[u] - pot[v];
                parent[v] = i;
                pq.emplace(prio[v], v);
            }
        }
    }
    if(prio[t] == INFLL) return 0LL;
    ll bneck = INFLL;
    for(int i = parent[t]; i != -1; i = parent[eg[i].u]) {
        bneck = min(bneck, eg[i].cap);
    }
    return bneck;
}

pll minCostMaxFlow(int s, int t, ll k = INFLL) {
    ll f = 0LL, cost = 0LL, bneck;
    spfa(s);
    while(f < k && (bneck = dijkstra(s, t))) {
        bneck = min(bneck, k - f);
        for(int i = 0; i < n; i++) {
            if(prio[i] != INFLL) {
                pot[i] += prio[i];
            }
        }
        for(int i = parent[t]; i != -1; i = parent[eg[i].u]) {
            eg[i].cap -= bneck;
            eg[i ^ 1].cap += bneck;
            cost += eg[i].cost * bneck;
        }
        f += bneck;
    }
    return {f, cost};
}

void addEdge(int u, int v, ll cap, ll cost) {
    eg.emplace_back(u, v, start[u], cap, cost);
    start[u] = eg.size() - 1;
}

void setEdge(int u, int v, ll cap, ll cost, int f = 0) {
    addEdge(u, v, cap, cost);
    addEdge(v, u, 0LL, -cost);
    if(f) {
        addEdge(v, u, cap, cost);
        addEdge(u, v, 0LL, -cost);
    }
}

void preprocess() {
    eg.clear();
    fill(start, start + n, -1);
}