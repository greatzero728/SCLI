#define _mx 17 // 1 << _mx > n
int dep[NN], pa[NN][_mx], head[NN], nxt[MM], to[MM], E;

struct LCA {
	void dfs(int u) {
		int e = 0, v;
		while(++e < _mx) pa[u][e] = pa[pa[u][e - 1]][e - 1];
		for(e = head[u]; ~e; e = nxt[e]) if((v = to[e]) ^ pa[u][0]) {
			dep[v] = dep[pa[v][0] = u] + 1, dfs(v);
		}
	}
	int k_th(int u, int k) {
		while(k) u = pa[u][__builtin_ctz(k)], k ^= k & -k;
		return u ? u : 1;
	}
	int lca(int u, int v) {
		if(dep[u] < dep[v]) swap(u, v);
		if((u = k_th(u, dep[u] - dep[v])) == v) return u;
		int i = _mx;
		while(i--) if(pa[u][i] ^ pa[v][i]) u = pa[u][i], v = pa[v][i];
		return pa[u][0];
	}
} lc;

void init(int n) {
	E = 0;
	while(head[n] = -1, n--);
}