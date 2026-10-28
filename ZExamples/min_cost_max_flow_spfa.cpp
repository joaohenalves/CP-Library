//UVA 10594

#include <bits/stdc++.h>
using namespace std;

#define MAX 112
#define MAXG 1123
#define INFLL 11234567891234567
#define MOD 998244353
#define EPS 1e-9
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int> tiii;

struct edge {
    int u, v, nxt; ll cap, cost;
    edge() {}
    edge(int _u, int _v, int _nxt, ll _cap, ll _cost) :
        u(_u), v (_v), nxt(_nxt), cap(_cap), cost(_cost) {}
};

int n, m, arr[MAX], inQueue[MAX], start[MAX], parent[MAX];
ll d, k, dist[MAX];
vector<edge> eg;

ll spfa(int s, int t) {
    // retorna o bneck, ou 0 se nenhum caminho foi encontrado
    fill(dist, dist + n, INFLL);
    memset(inQueue, 0, sizeof(inQueue));
    memset(parent, -1, sizeof(parent));
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
    while(bneck = spfa(s, t)) {
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

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int u, v, c = 1;
    ll cost;
    while(cin >> n >> m) {
        eg.clear();
        memset(start, -1, sizeof(start));
        for(int i = 0; i < m; i++) {
            cin >> u >> v >> cost;
            addEdge(u, v, 1, cost); //aresta original
            addEdge(v, u, 0, -cost); //aresta reversa, deve ser imediatamente a proxima a ser inserida
            addEdge(v, u, 1, cost); //o grafo do problema é não direcionado! portanto, as outras duas arestas devem ser inseridas
            addEdge(u, v, 0, -cost);
        }
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
        pll ans = minCostMaxFlowFfek(0, n - 1);
        cout << "Instancia " << c << '\n';
        if(ans.first < d) cout << "impossivel\n\n";
        else cout << ans.second << "\n\n";
        c++;
    }    
    return 0;
}