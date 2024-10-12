#define _mx 17 // 1 << _mx > n
int dep[NN], head[NN], nxt[MM], to[MM], E;

struct LCA {
	int a[NN], s[NN << 1], mn[NN << 1][_mx + 1], nc;
	
	int g(int u, int v) {return a[u] < a[v] ? u : v;}
	void dfs(int u, int f = -1) {
		s[a[u] = nc++] = u;
		for(int e = head[u], v; ~e; e = nxt[e]) if((v = to[e]) ^ f) {
			dep[v] = dep[u] + 1, dfs(v, u), s[nc++] = u;
		}
	}
	int lca(int u, int v) {
		int k; u = a[u], v = a[v];
		if(u > v) k = u, u = v, v = k;
		k = 31 - __builtin_clz(v - u + 1);
		return g(mn[u][k], mn[v - (1 << k) + 1][k]);
	}
	void init() {
		nc = 0, dfs(1);
		int i = nc, j = 0;
		while(i--) mn[i][0] = s[i];
		while(j++ < _mx) for(i = nc; i--; )
		if(i + (1 << j - 1) < nc) mn[i][j] = g(mn[i][j - 1], mn[i + (1 << j - 1)][j - 1]);
		else mn[i][j] = mn[i][j - 1];
	}
} lc;

void init(int n) {
	E = 0;
	while(head[n] = -1, n--);
}