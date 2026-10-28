// 1 - INDEXED
// (i1, j1) canto superior esquerdo
// (i2, j2) canto inferior direito
// (na perspectiva de uma matriz normal)
// cuidado com overflow

int grid[MAXG][MAXG];

void update(int i1, int j1, int i2, int j2, int val) {
    grid[i1][j1] += val;
    grid[i1][j2 + 1] -= val;
    grid[i2 + 1][j1] -= val;
    grid[i2 + 1][j2 + 1] += val;
}

void queryAll() {
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            grid[i][j] += grid[i - 1][j] + grid[i][j - 1] - grid[i - 1][j - 1];
            // resposta contida na célula grid[i][j]
        }
    }
}