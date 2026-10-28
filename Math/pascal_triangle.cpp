// 0 ESCOLHE 0 É 1 !!!!
// maxg menor que 60 preferencialmente

ll binom[MAXG][MAXG];

void pascal() {
    for(int x = 0; x < MAXG; x++) {
        for(int y = 0; y <= x; y++) {
            if(y == 0 || y == x) binom[x][y] = 1;
            else binom[x][y] = binom[x - 1][y - 1] + binom[x - 1][y];
        }
    }
}