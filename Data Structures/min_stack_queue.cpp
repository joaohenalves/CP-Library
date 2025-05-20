// simulação de queue com duas stacks
// é a melhor escolha para resolver o problema:
// "encontrar o mínimo de todos os subarrays de tamanho k"
// inserir os primeiros k números, pegar o mínimo, e para cada novo elemento i
// só chamar insertStk(arr[i]) e chamar removeStk()

stack<pii> stk1, stk2;

void insertStk(int x) {
    int y = stk1.empty() ? x : min(x, stk1.top().second);
    stk1.emplace(x, y);
}

void removeStk() {
    if(stk2.empty()) {
        while(!stk1.empty()) {
            int x = stk1.top().first;
            stk1.pop();
            int y = stk2.empty() ? x : min(x, stk2.top().second);
            stk2.emplace(x, y);
        }
    }
    stk2.pop();
}

int findMinStk() {
    if(stk1.empty() || stk2.empty()) {
        return stk1.empty() ? stk2.top().second : stk1.top().second;
    } else return min(stk1.top().second, stk2.top().second);
}
