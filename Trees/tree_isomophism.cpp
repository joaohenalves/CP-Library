// Retorna true se duas árvores são isomórficas

int c, degree[MAX], center[2];
vector<vector<int>> graph1(MAX);
vector<vector<int>> graph2(MAX);

void treeCenter(vector<vector<int>> &graph) {
    queue<int> leaves;
    int u, q2, q = 0, counter = 0;
    c = 0;
    for(u = 0; u < n; u++) {
        degree[u] = graph[u].size();
        if(degree[u] == 1) {
            leaves.push(u);
            counter++;
            q++;
        }
    }
    while(counter < n) {
        q2 = 0;
        for(int i = 0; i < q; i++) {
            u = leaves.front();
            leaves.pop();
            for(int &v : graph[u]) {
                degree[v]--;
                if(degree[v] == 1) {
                    leaves.push(v);
                    counter++;
                    q2++;
                }
                degree[u] = 0;
            }
        }
        q = q2;
    }
    while(!leaves.empty()) { center[c++] = leaves.front(); leaves.pop(); }
}

string encode(int u, int p, vector<vector<int>> &graph) {
    vector<string> labels;
    for(int &v : graph[u]) {
        if(v != p) labels.push_back(encode(v, u, graph));
    }
    sort(labels.begin(), labels.end());
    string result = "";
    for(auto &s : labels) {
        result += s;
    }
    return "(" + result + ")";
}

bool isomorphic() {
    treeCenter(graph1);
    int t1 = c;
    string tree1 = encode(center[0], -1, graph1);
    treeCenter(graph2);
    if(t1 != c) return false;
    for(int i = 0; i < c; i++) {
        if(tree1 == encode(center[i], -1, graph2)) {
            return true;
        }
    }
    return false;
}