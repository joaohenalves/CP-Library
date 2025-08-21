// dada uma lista fib com uma quantidade "idx" de numeros de fibonacci, calcula
// uma possivel decomposição de um numero n em fatores de fibonacci (pode não existir tal fatoração)

int flag = 0;
vector<ll> factors;

void factorize(ll n, int idx) {
    if(flag) return;
    if(n == 1) {
        //fatores estarão em factors, processar a resposta aqui
        flag = 1;
        return;
    }
    for(int i = idx; i > 2; i--) {
        if (n % fib[i] == 0) {
            factors.push_back(i);
            factorize(n / fib[i], i);
            factors.pop_back();
        }
    }
}