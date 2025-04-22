int dist[MAXG][MAXG];
int ai[] = {-1, 1, 0, 0};
int aj[] = {0, 0, 1, -1};

void bfs(int si, int sj) {
    queue<pii> q;
    int ii, jj;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            dist[i][j] = INF;
        }
    }
    dist[si][sj] = 0;
    q.emplace(si, sj);
    while(!q.empty()) {
        auto [i, j] = q.front();
        q.pop();
        for(int k = 0; k < 4; k++) {
            ii = i + ai[k];
            jj = j + aj[k];
            if(ii >= 0 && ii < n && jj >= 0 && jj < m && dist[ii][jj] == INF) {
                dist[ii][jj] = dist[i][j] + 1;
                q.emplace(ii, jj);
            }
        }
    }
}