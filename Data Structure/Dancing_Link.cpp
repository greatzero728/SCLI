struct Dl {
	#define NR 1010
	#define NC 101010 // sz(col) + sz(insert)
	bool h[NC];
	int L[NC], R[NC], U[NC], D[NC], sz;
	int C[NC], X[NC], S[NC], H[NR], ans;
	int c() {
		int s = 0, c = R[0], i, j;
		while(c) h[c] = 1, c = R[c];
		for(c = R[0]; c; c = R[c]) if(h[c])
		for(h[c] = 0, s++, i = D[c]; i ^ c; i = D[i])
		for(j = R[i]; j ^ i; j = R[j]) h[C[j]] = 0;
		return s;
	}
	void d(int c) {
		int i = D[c];
		while(i ^ c) R[L[R[i]] = L[i]] = R[i], S[C[i]]--, i = D[i];
	}
	void g(int c) {
		int i = U[c];
		while(i ^ c) S[C[L[R[i]] = R[L[i]] = i]]++, i = U[i];
	}
	int dfs(int k = 0) {
		if(k + c() >= ans) return 0;
		if(!R[0]) return ans = k;
		int c = R[0], i = c, j;
		for(; i; i = R[i]) if(S[i] < S[c]) c = i;
		for(i = D[c]; i ^ c; i = D[i]) {
			for(d(i), j = R[i]; j ^ i; j = R[j]) d(j); dfs(k + 1);
			for(j = L[i]; j ^ i; j = L[j]) g(j); g(i);
		}
	}
	void insert(int x, int y) {
		S[C[sz] = y]++;
		X[U[D[sz] = D[y]] = sz] = x, U[D[y] = sz] = y;
		if(~(y = H[x])) R[L[sz] = L[y]] = sz, R[L[y] = sz] = y;
		else H[x] = L[sz] = R[sz] = sz; sz++;
	}
	void init(int n, int m) {
		while(H[n] = -1, --n);
		while(n <= m) L[n] = n - 1, R[U[n] = D[n] = n] = n + 1, S[n++] = 0;
		L[R[m] = 0] = m, sz = m + 1, ans = NR;
	}
} dl;
// think n * m matrix (initialize : init(n, m))
// Let's imagine that if you select xth row, then yth col is automatically selected.
// Select some rows and then think about the columns that will select by those selected rows.
// 1. We have to get the state that number of selected columns is maximum.
//    (If there are more than one state, then you must get the state that the number of selected rows is minumum)
//    dl.dfs(), cout<<"minimum number of rows = "<<dl.ans;
// 2. We have to get the state that number of selected columns is minimum.
//    (If there are more than one state, then you must get the state that the number of selected rows is maximum)
//    You must change like if(k + c() >= ans) ==>> if(k + c() <= ans) in dfs function.
//    You must change like ans = NR ==>> ans = 0 in init function.
//    dl.dfs(), cout<<"maximum number of rows = "<<dl.ans;
    
    dl.dfs(), cout<<"ans = "<<dl.ans;