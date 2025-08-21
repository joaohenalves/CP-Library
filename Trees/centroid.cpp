// Encontra o(s) centróide(s) da árvore (existem 1 ou 2 somente)
// Um centróide é um nodo que não possui nenhum filho com mais de floor(n / 2) filhos

int tsize[MAX];
vector<int> centroid;

void dfs(int u, int p) {
    int flag = 0, s = 0;
    for(int &v : graph[u]) {
        if(v != p) {
            dfs(v, u);
            if(tsize[v] > n / 2) flag = 1;
            s += tsize[v];
        }
    }
    if(flag == 0 && n - s - 1 <= n / 2) {
        centroid.push_back(u);
    }
    tsize[u] = s + 1;
}