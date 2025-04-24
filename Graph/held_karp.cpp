// calcula o ciclo hamiltoniano de menor custo

// atenção, o vértice de origem aqui é o 0! fortes ajustes devem ser feitos
// caso a origem desejada seja outro vértice
// mas pode-se sempre "trocar" o identificador do vértice de origem desejado com o 0, fica mais fácil (gambiarra)

int graph[MAX_V][MAX_V], dp[1 << MAX_V][MAX_V];

int heldKarp() {
    int i, j, ans, mask, last, next, newMask;
    for(mask = 0; mask < (1 << n); mask++) {
        for(i = 0; i < n; i++) {
            dp[mask][i] = INF;
        }
    }
    dp[1][0] = 0;
    for(mask = 1; mask < (1 << n); mask++) {
        for(last = 0; last < n; last++) {
            if(dp[mask][last] == INF) continue;
            for(next = 0; next < n; next++) {
                if(!(mask & (1 << next))) {
                    newMask = mask | (1 << next);
                    dp[newMask][next] = min(dp[newMask][next], dp[mask][last] + graph[last][next]);
                }
            }
        }
    }
    ans = INF;
    for (i = 1; i < n; i++) {
        ans = min(ans, dp[(1 << n) - 1][i]); // + graph[i][0] caso o retorno ao início seja necessário. i = último vértice escolhido do caminho e 0 é o vértice de início
    }
    return ans;
}
