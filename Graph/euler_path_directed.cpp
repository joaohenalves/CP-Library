// euler path para grafos dirigidos
// aqui, inicio = 0 e final = n - 1
// m deve conter o número de arestas

int idx, path[MAX], inDegree[MAX], outDegree[MAX];
stack<int> stk;
 
void eulerPath(int start) {
    stk.push(start);
    idx = 0;
    while(!stk.empty()) {
        int u = stk.top();
        if(outDegree[u] == 0) {
            path[idx++] = u;
            stk.pop();
        } else {
            int v = graph[u].back();
            graph[u].pop_back();
            outDegree[u]--;
            stk.push(v);
        }
    }
    reverse(path, path + idx);
}

void setEdge(int u, int v) {
    graph[u].push_back(v);
    outDegree[u]++;
    inDegree[v]++;
}

bool isValid() {
    int flag = 1, start = 0, ending = n - 1;
    if(outDegree[start] - inDegree[start] != 1 || inDegree[ending] - outDegree[ending] != 1) {
        flag = 0;
    } else {
        for(int i = 1; i < ending; i++) {
            if(inDegree[i] != outDegree[i]) {
                flag = 0;
                break;
            }
        }
    }
    if(flag) {
        eulerPath(start);
        if(idx == m + 1 && path[idx - 1] == n - 1) {
            for(int i = 0; i < idx; i++) {
                cout << path[i] + 1 << ' ';
            }
            cout << '\n';
        } else flag = 0;
    }
    return flag;
}