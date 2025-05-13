// compressão de números
// lê os numeros em arr e escreve devolta em arr seus valores comprimidos

void compress() {
    map<int, int> remap;
    int idx = 0;
    for(int i = 0; i < n; i++) {
        remap[arr[i]] = 0;
    }
    for(auto &[key, val] : remap) {
        val = idx++;
    }
    for(int i = 0; i < n; i++) {
        arr[i] = remap[arr[i]];
    }
}

// Ou outra alternativa:
void compress() {
    vector<int> aux(arr, arr + n);
    sort(aux.begin(), aux.end());
    aux.erase(unique(aux.begin(), aux.end()), aux.end());
    for(int i = 0; i < n; i++) {
        arr[i] = int(lower_bound(aux.begin(), aux.end(), arr[i]) - aux.begin());
    }
}