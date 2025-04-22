// dado um alfabeto A e um tamanho n, constrói uma string tal que 
// todas as strings possíveis de tamanho n com o alfabeto A
// aparecem exatamente uma vez como substring da string de saída
// Complexidade: O(2^n)
 
unordered_set<string> seen;
vector<int> edges;
 
void dfs(string node, int& k, string& A){
    for(int i = 0; i < k; ++i) {
        string str = node + A[i];
        if(seen.find(str) == seen.end()) {
            seen.insert(str);
            dfs(str.substr(1), k, A);
            edges.push_back(i);
        }
    }
}
 
string deBruijn(int n) {
    string A = "01"; // alfabeto
    int k = 2; // tamanho do alfabeto
    // n = tamanho das substrings
    seen.clear();
    edges.clear();
    string startingNode = string(n - 1, A[0]);
    dfs(startingNode, k, A);
    string S;
    int l = pow(k, n);
    for(int i = 0; i < l; ++i)
        S += A[edges[i]];
    S += startingNode;
    return S;
}