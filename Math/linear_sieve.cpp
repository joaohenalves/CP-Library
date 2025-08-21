int pi, lp[MAX], pr[MAX];

void linearSieve() {
	pi = 0;
	for(int i = 2; i < MAX; i++) {
		if(lp[i] == 0) {
			lp[i] = i;
			pr[pi++] = i;
		}
		for(int j = 0; i * pr[j] < MAX; j++) {
			lp[i * pr[j]] = pr[j];
			if(pr[j] == lp[i]) break;
		}
	}
}
 
vector<int> factorize(int x) {
	vector<int> factors;
	while(x > 1) {
		if(factors.empty() || factors.back() != lp[x]) {
            factors.push_back(lp[x]);
        }
		x /= lp[x];
	}
    return factors;
}