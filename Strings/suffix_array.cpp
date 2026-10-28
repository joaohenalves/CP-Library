//owwer[i] = a qual string pertence o sufixo (0 = a, 1 = b, na ordem construida em preprocess(a, b))
//sa[i] = indice do sufixo na string a + $ + b + #
//lcp[i] = tamanho do maior prefixo comum com relação ao sufixo anterior (já ordenados)
//ra[i] = posição dentro do suffix array que o sufixo que começa na posição i da string original está
//o resto são vetores só usados na construção do array
//caracteres extras no final de cada string devem ser atribuidos em ordem DECRESCENTE ('$' > '#')
//n e k globais
//tamanho dos vetores deve ser pelo menos 2 * (maior tamanho das strings) + 2
//cuidado com buscas no lcp em algum intervalo [l, r] porque os resultados que
//importam estao em [l + 1, r] (já que o lcp[i] é com relação ao sa[i - 1])


#define _ra(i) ((i) < n ? ra[i] : 0)

int owner[MAX], sa[MAX], lcp[MAX], ra[MAX], tempra[MAX], phi[MAX], plcp[MAX];
string s;

bool cmp(int i, int j) {
    return pii(ra[i], _ra(i + k)) < pii(ra[j], _ra(j + k));
}

void compute_lcp() {
    phi[sa[0]] = -1;
    for(int i = 1; i < n; i++) phi[sa[i]] = sa[i - 1];
    for(int i = 0, l = 0; i < n; i++) {
        if(phi[i] == -1) {
            plcp[i] = 0;
            continue;
        }
        while(s[i + l] == s[phi[i] + l]) l++;
        plcp[i] = l--;
        l = max(0, l);
    }
    for(int i = 0; i < n; i++) {
        lcp[i] = plcp[sa[i]];
    }
}

void build_sa() {
    int r;
    for(int i = 0; i < n; i++) {
        sa[i] = i;
        ra[i] = s[i];
    }
    for(k = 1; k < n; k <<= 1) {
        sort(sa, sa + n, cmp);
        tempra[sa[0]] = r = 0;
        for(int i = 1; i < n; i++) {
            tempra[sa[i]] = ra[sa[i]] == ra[sa[i - 1]] && 
                _ra(sa[i] + k) == _ra(sa[i - 1] + k) ? r : ++r;
        }
        for(int i = 0; i < n; i++) ra[i] = tempra[i];
        if(ra[sa[n - 1]] == n - 1) break;
    }
}

void suffix_array(string &a, string &b) {
    s = a + "$" + b + "#";
    n = (int) s.size();
    for(int i = 0;  i < n; i++) {
        owner[i] = i > (int) a.size();
    }
    build_sa();
    compute_lcp();
}

int max_common_substr() {
    int ans = 0;
    for(int i = 1; i < n; i++) {
        if(owner[sa[i]] != owner[sa[i - 1]]) {
            ans = max(ans, lcp[i]);
        }
    }
    return ans;
}