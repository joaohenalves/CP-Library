//calcula os coeficientes binomiais para qualquer número n de 1 até cn, para um ck fixo
//vai bem quando computar os fatoriais para a fórmula direta não é possível
//(quando falta um mod para as operações, por exemplo)


// forma fácil, mas cuidado com overflow
ll cn, ck, cf[MAX];

void compute() {
    for(int i = 0; i < ck; i++) cf[i] = 0;
    cf[ck] = 1;
    for(ll i = ck + 1; i <= cn; i++) {
        __int128 t = (__int128) cf[i - 1] * i;
        t /= (i - ck);
        cf[i] = (ll) t;
    }
}

