int bel[NN], vst[NN], low[NN];
int head[NN], nxt[MM], to[MM], E;
int st[NN], ins[NN], nc, nt, cnt;

void _dfs(int u) {
	int[u] = 1;
	vst[st[++nt] = u] = low[u] = ++nc;
	for(int e = head[u], v; ~e; e = nxt[e]) {
		if(!vst[v = to[e]]) {
			_dfs(v);
			if(low[v] < low[u]) low[u] = low[v];
		}
		else if(ins[v] && vst[v] < low[u]) low[u] = vst[v];
	}
	if(vst[u] == low[u]) {
		cnt++;
		while(bel[st[nt]] = cnt, ins[st[nt]] = 0, st[nt--] ^ u);
	}
}
void init(int n) {
	E = cnt = nc = 0;
	while(vst[n] = 0, head[n] = -1, n--);
}