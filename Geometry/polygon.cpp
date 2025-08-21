//Calcula a area do polígono simples, convexo ou nao
//vetor de pontos do parâmetro deve conter a lista de pontos do polígono
//nenhuma posição sobrando, e sem repetições de pontos
//point aqui deve ter as coordenadas long long
//os vértices devem estar ordenados no sentido horário ou anti-horário,
//se não, não funciona

double polArea(vector<point> &p) {
    p.emplace_back(p[0]); //repete o primeiro ponto no final
    ll ans = 0;
    for(int i = 0; i < (int) p.size() - 1; i++) {
        ans += p[i].x * p[i + 1].y - p[i].y * p[i + 1].x;
    }
    return 0.5 * llabs(ans); //llabs(ans) conterá 2 * area
}