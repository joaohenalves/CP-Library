typedef pair<ll, ll> pll;

int start[MAX], parent[MAX];
ll d, k, prio[MAX], pot[MAX];
vector<edge> eg;

struct edge {
    int u, v, nxt; ll cap, cost;
    edge() {}
    edge(int _u, int _v, int _nxt, ll _cap, ll _cost) :
        u(_u), v (_v), nxt(_nxt), cap(_cap), cost(_cost) {}
};

ll dijkstra(int s, int t) {
    // retorna o bneck, ou 0 se nenhum caminho foi encontrado
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    fill(prio, prio + n, INFLL);
    memset(parent, -1, sizeof(parent));
    prio[s] = 0;
    pq.emplace(0, s);
    while(!pq.empty()) {
        auto [du, u] = pq.top(); 
        pq.pop();
        if(prio[u] < du) continue;
        for(int i = start[u]; i != -1; i = eg[i].nxt) {
            int v = eg[i].v;
            if(eg[i].cap > 0 && prio[v] > du + eg[i].cost + pot[u] - pot[v]) {
                prio[v] = du + eg[i].cost + pot[u] - pot[v];
                pq.emplace(prio[v], v);
                parent[v] = i;
            }
        }
    }
    if(prio[t] == INFLL) return 0;
    ll bneck = INFLL;
    for(int i = parent[t]; i != -1; i = parent[eg[i].u]) {
        bneck = min(bneck, eg[i].cap);
    }
    return bneck;
}

void bellmanFord(int s) {
    fill(pot, pot + n, INFLL);
    pot[s] = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            for(int k = start[j]; k != -1; k = eg[k].nxt) {
                int v = eg[i].v;
                if(eg[i].cap > 0 && pot[v] > pot[j] + eg[i].cost) {
                    pot[v] = pot[j] + eg[i].cost;
                }
            }
        }
    }
}

pll minCostMaxFlow(int s, int t) {
    ll f = 0, cost = 0, bneck;
    bellmanFord(s);
    while(bneck = dijkstra(s, t)) {
        f += bneck;
        for(int i = 0; i < n; i++) pot[i] += prio[i];
        for(int i = parent[t]; i != -1; i = parent[eg[i].u]) {
            eg[i].cap -= bneck;
            eg[i ^ 1].cap += bneck;
            cost += eg[i].cost * bneck;
        }
    }
    return {f, cost};
}

void addEdge(int u, int v, ll cap, ll cost) {
    eg.emplace_back(u, v, start[u], cap, cost);
    start[u] = eg.size() - 1;
}

void setGraph() {
    int u, v, c = 1;
    ll cost;
    eg.clear();
    memset(start, -1, sizeof(start));
    for(int i = 0; i < m; i++) {
        cin >> u >> v >> cost;
        addEdge(u, v, 1, cost); //aresta original
        addEdge(v, u, 0, -cost); //aresta reversa, deve ser imediatamente a proxima a ser inserida
        //se o grafo for não direcionado, inserir mais as outras duas arestas abaixo
        addEdge(v, u, 1, cost);
        addEdge(u, v, 0, -cost);
    }
    cin >> d >> k;
    for(auto &e : eg) e.cap *= k;
    addEdge(0, 1, d, 0);
    addEdge(1, 0, 0, 0);
    n++;
    cin >> d >> k;
    for(auto &e : eg) e.cap *= k;
    addEdge(0, 1, d, 0);
    addEdge(1, 0, 0, 0);
    n++;
    //neste problema, é preciso saber o custo mínimo de se enviar
    // 'd' unidades de fluxo, que não necessariamente é máximo.
    //portanto, um vértice extra, o zero, é colocado no grafo, com uma aresta
    //de capacidade 'd' indo para o vértice 1, para limitar o fluxo em 'd'.
    //os outros vértices, que normalmente teriam seus identificadores decrementados
    //para trabalhar com indexação em 0, permanecem os mesmos. finalmente, n é incrementado
    //para corresponder ao novo número de vértices do grafo.
    pll ans = minCostMaxFlow(0, n - 1);
    cout << "Instancia " << c << '\n';
    if(ans.first < d) cout << "impossivel\n\n";
    else cout << ans.second << "\n\n";
    c++;
}