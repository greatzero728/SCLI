int bel[NN], vst[NN], low[NN];
int head[NN], nxt[MM], to[MM];
int st[NN], nc, nt, cnt, E;

void _dfs(int u, int f = -1) {
	vst[st[++nt] = u] = low[u] = ++nc;
	for(int e = head[u], v; ~e; e = nxt[e]) {
		if(!vst[v = to[e]]) {
			_dfs(v, e);
			if(low[v] < low[u]) low[u] = low[v];
		}
		else if(e ^ f ^ 1 && vst[v] < low[u]) low[u] = vst[v];
	}
	if(vst[u] == low[u]) {
		cnt++;
		while(bel[st[nt]] = cnt, u ^ st[nt--]);
	}
}
void init(int n) {
	E = cnt = nc = 0;
	while(vst[n] = 0, head[n] = -1, n--);
}