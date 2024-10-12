struct Dlx {
	#define NR 212
	#define NC 1212
	int L[NC], R[NC], U[NC], D[NC], C[NC], X[NC], S[NC];
	int ans[NR], H[NR], O[NR], sz, nn, nc;
	void d(int c) {
		L[R[L[c]] = R[c]] = L[c];
		for(int i = D[c], j; i ^ c; i = D[i])
		for(j = R[i]; j ^ i; j = R[j]) D[U[D[j]] = U[j]] = D[j], S[C[j]]--;
	}
	void g(int c) {
		for(int i = U[c], j; i ^ c; i = U[i])
		for(j = L[i]; j ^ i; j = L[j]) S[C[U[D[j]] = D[U[j]] = j]]++;
		L[R[c]] = R[L[c]] = c;
	}
	int dfs(int k = 0) {
		if(nc >= nn) return 0;
		int c = R[0], i = c, j = k;
		if(!i) {while(j--) ans[j] = O[j]; return nc++;}
		for(; i; i = R[i]) if(S[i] < S[c]) c = i;
		for(d(c), i = D[c]; i ^ c; i = D[i]) {
			for(O[k] = X[i], j = R[i]; j ^ i; j = R[j]) d(C[j]); dfs(k + 1);
			if(nc >= nn) return 0;
			for(j = L[i]; j ^ i; j = L[j]) g(C[j]);
		}
		return g(c), 0;
	}
	void insert(int x, int y) {
		S[C[sz] = y]++, X[U[D[sz] = D[y]] = sz] = x, U[D[y] = sz] = y;
		if(~(y = H[x])) R[L[sz] = L[y]] = sz, R[L[y] = sz] = y;
		else H[x] = L[sz] = R[sz] = sz;
		sz++;
	}
	void init(int n, int m, int f) {
		while(H[n] = -1, --n);
		while(n <= m) L[n] = n - 1, R[U[n] = D[n] = n] = n + 1, S[n++] = 0;
		L[R[m] = nc = 0] = m, sz = m + 1, nn = f;
	}
} dx;

// almost similar to DancingLink.
// You can get the f patterns that all columns to be selected.
// initialize : init(n, m, f);
// For every cloumns, that rules are allowed.
// The rows that effect that column is always once selected.
// 
// The number of patterns that select the rows is nc.
// We save the anwer in that part in dfs function.
// if(!i) {while(j--) ans[j] = O[j]; return nc++;}
// 
// So if we are in dfs(k), then the number of rows are ans[0], ans[1], ... , ans[k - 1].