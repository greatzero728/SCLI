#define _ make_pair

struct simplex { //0-based
	//max{cx} subject to {ax <= b, x >= 0}
	static const int nr = 101, nc = 101;
	DO a[nr][nc], b[nr], c[nc], s[nr][nc], x[nc];
	int I[nr], t[nc], n, m;
	
	void rot(int x, int y) {
		int i = -1, j; swap(I[x], t[y]);
		while(i++ < n) if(i ^ x && fabs(s[i][y]) > eps)
		for(j = m + 1; j--; ) if(j ^ y) s[i][j] -= s[x][j] * s[i][y] / s[x][y];
		while(i--) if(i ^ x) s[i][y] /= -s[x][y];
		while(i++ < m) if(i ^ y) s[x][i] /= s[x][y];
		s[x][y] = 1 / s[x][y];
	}
	DO calc(int N, int M) {
		n = N; int i = m = M;
		while(s[0][i] = -c[t[i] = i], i--); s[0][m] = 0;
		while(++i < n) for(N = m; N--; ) s[i + 1][N] = a[i][N];
		while(i--) s[i + 1][m] = b[i], I[i] = -i;
		while(N = 1) {
			for(M = 0, i = n; i; i--) if(_(s[i][m], I[i]) < _(s[N][m], I[N])) N = i;
			if(s[N][i = m] > -eps) break;
			while(i--) if(s[N][i] < s[N][M]) M = i;
			if(s[N][M] > -eps) return -1e20; //no solution
			rot(N, M);
		}
		while(N = 1) {
			M = 0, i = m;
			while(i--) if(_(s[0][i], t[i]) < _(s[0][M], t[M])) M = i;
			if(s[++i][M] > -eps) break;
			while(i++ < n) if(s[i][M] > eps)
			if(_(s[i][m] / s[i][M], I[i]) < _(s[N][m] / s[N][M], I[N]) || s[N][M] < eps) N = i;
			if(s[N][M] < eps) return 1e20; //inf solution
			rot(N, M);
		}
		i = m; while(x[--i] = 0, i);
		while(i++ < n) if(I[i] >= 0) x[I[i]] = s[i][m];
		return s[0][m];
	}
} si;