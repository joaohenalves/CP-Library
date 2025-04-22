// Exponenciação de matrizes binárias, onde os valores são somente 0 ou 1
// Utiliza o "método dos quatro russos" para otimizar a parte de multiplicação, altamente eficiente
// Bruxaria total, não tem como entender

// Valores iniciais e resultado ficam em 'a'

vector<bitset<MAXG>> a, b;
 
void multmat(vector<bitset<MAXG>> &a, vector<bitset<MAXG>> &b, int ord) {
    vector<bitset<MAXG>> result(ord);
    for(int i = 0; i < ord; i++) {
        result[i].reset();
        for(int k = 0; k < ord; k++) {
            if(a[i][k]) {
                result[i] |= b[k];
            }
        }
    }
    a = result;
}
 
void ident(vector<bitset<MAXG>> &a, int ord) {
    a.resize(ord);
    for(int i = 0; i < ord; i++) {
        a[i].reset();
        a[i][i] = 1;
    }
}
 
void expbin(vector<bitset<MAXG>> &a, int k, int ord) {
    ident(b, ord);
    while(k) {
        if(k & 1) {
            multmat(b, a, ord);
        }
        multmat(a, a, ord);
        k >>= 1;
    }
    a = b;
}