//cuidado com o subset vazio, se faz sentido ter ou pegar algo dele

int dp[MAX];

void sos_dp() {
    for(int i = 0; i < (1 << n); i++) {
        dp[i] = arr[i]; // resposta para o subset individual de mascara i
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < (1 << n); j++){
            if(j & (1 << i)) {
                dp[j] += dp[j ^ (1 << i)];
            }
        }
    }
}