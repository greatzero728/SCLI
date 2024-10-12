bool vst[NN];
int sz[NN], fa[NN], q[NN], qf, qb;
int head[NN], nxt[MM], to[MM], E;
int cen(int u) {
	int v, e, x;
	for(fa[q[qf = 0] = u] = -1, qb = 1; qf < qb; ) {
		for(e = head[u = q[qf++]]; ~e; e = nxt[e]) {
			if(fa[u] == (v = to[e]) || vst[v]) continue;
			fa[v] = u, q[qb++] = v;
		}
	}
	while(qf--) {
		for(x = 0, sz[u = q[qf]] = 1, e = head[u]; ~e; e = nxt[e]) {
			if(fa[u] == (v = to[e]) || vst[v]) continue;
			if(sz[v] > x) x = sz[v]; sz[u] += sz[v];
		}
		if(x << 1 <= qb && sz[u] << 1 >= qb) return u;
	}
}
void init(int n) {
	E = 0; while(vst[n] = 0, head[n] = -1, n--);
}