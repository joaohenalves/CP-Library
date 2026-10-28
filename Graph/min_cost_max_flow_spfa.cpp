// passar o parametro f = 1 no setEdge se o grafo nao for dirigido

struct edge {
    int u, v, nxt; ll cap, cost;
    edge() {}
    edge(int _u, int _v, int _nxt, ll _cap, ll _cost) :
        u(_u), v (_v), nxt(_nxt), cap(_cap), cost(_cost) {}
};

typedef pair<ll, ll> pll;
int inQueue[MAX], start[MAX], parent[MAX];
ll dist[MAX];
vector<edge> eg;

ll spfa(int s, int t) {
    // retorna o bneck, ou 0 se nenhum caminho foi encontrado
    fill(dist, dist + n, INFLL);
    fill(inQueue, inQueue + n, 0);
    fill(parent, parent + n, -1);
    queue<int> q;
    dist[s] = 0;
    inQueue[s] = 1;
    q.push(s);
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        inQueue[u] = 0;
        for(int i = start[u]; i != -1; i = eg[i].nxt) {
            int v = eg[i].v;
            if(eg[i].cap > 0 && dist[v] > dist[u] + eg[i].cost) {
                dist[v] = dist[u] + eg[i].cost;
                parent[v] = i;
                if(inQueue[v] == 0) {
                    q.push(v);
                    inQueue[v] = 1;
                }
            }
        }
    }
    if(dist[t] == INFLL) return 0;
    ll bneck = INFLL;
    for(int i = parent[t]; i != -1; i = parent[eg[i].u]) {
        bneck = min(bneck, eg[i].cap);
    }
    return bneck;
}

pll minCostMaxFlowFfek(int s, int t) {
    ll f = 0, cost = 0, bneck;
    while((bneck = spfa(s, t))) {
        f += bneck;
        cost += bneck * dist[t];
        for(int i = parent[t]; i != -1; i = parent[eg[i].u]) {
            eg[i].cap -= bneck;
            eg[i ^ 1].cap += bneck;
        }
    }
    return {f, cost};
}

void addEdge(int u, int v, ll cap, ll cost) {
    eg.emplace_back(u, v, start[u], cap, cost);
    start[u] = eg.size() - 1;
}

void setEdge(int u, int v, ll cap, ll cost, int f) {
    addEdge(u, v, cap, cost);
    addEdge(v, u, 0, -cost);
    if(f) {
        addEdge(v, u, cap, cost);
        addEdge(u, v, 0, -cost);
    }
}

void preprocess() {
    eg.clear();
    fill(start, start + n, -1);
}
