//gera todas as partições possíveis de n elementos em conjuntos.
//complexidade: O(n * B(n)) em que B(N) é o número de Bell de n
//que é o número total de jeitos possíveis de fazer as partições.
//Ex: para n = 12, deve levar entre 1 e 2 segundos

//chamar search() com 0 (primeiro elemento a ser considerado)

vector<vector<int>> part;

void search(int i) {
    if(i == n) {
        //processa a partição
        for(auto &a : part) {
            //processa cada conjunto
            for(int &b : a) {
                //processa cada elemento do conjunto
            }
        }
        return;
    }
    for(int j = 0; j < part.size(); j++) {
        part[j].push_back(i);
        search(i + 1);
        part[j].pop_back();
    }
    part.push_back({i});
    search(i + 1);
    part.pop_back();
}