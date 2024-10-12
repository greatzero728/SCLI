int sz[NN], dep[NN], pa[NN], top[NN], hv[NN], nc;
int dfn[NN], I[NN], head[NN], nxt[MM], to[MM], E;

void dfs1(int u) {
	sz[u] = 1, hv[u] = -1;
	for(int e = head[u], mx = 0, v; ~e; e = nxt[e]) if((v = to[e]) ^ pa[u]) {
		dep[v] = dep[pa[v] = u] + 1, dfs1(v), sz[u] += sz[v];
		if(sz[v] > mx) mx = sz[hv[u] = v];
	}
}
void dfs2(int u, int f) {
	top[I[dfn[u] = ++nc] = u] = f;
	if(~hv[u]) dfs2(hv[u], f);
	for(int e = head[u]; ~e; e = nxt[e]) {
		f = to[e];
		if(f ^ pa[u] && f ^ hv[u]) dfs2(f, f);
	}
}
int lca(int u, int v) {
	for(; top[u] ^ top[v]; u = pa[top[u]]) if(dep[top[u]] < dep[top[v]]) swap(u, v);
	return dep[u] < dep[v] ? u : v;
}
void query(int u, int v) {
	for(; top[u] ^ top[v]; u = pa[top[u]]) {
		if(dep[top[u]] < dep[top[v]]) swap(u, v);
//		int L = dfn[top[u]], R = dfn[u];
	}
	if(dep[u] > dep[v]) swap(u, v);
//	int L = dfn[u], R = dfn[v];
}
void init(int n) {
	E = nc = 0;
	while(head[n] = -1, n--);
}