vector<vector<int> > bcc;
int head[NN], nxt[MM], to[MM], E;
int st[NN], vst[NN], low[NN], nc, nt;

void _dfs(int u, int f = -1) {
	vst[st[++nt] = u] = low[u] = ++nc;
	for(int e = head[u], v; ~e; e = nxt[e]) {
		if(!vst[v = to[e]]) {
			_dfs(v, u);
			if(low[v] < low[u]) low[u] = low[v];
			if(low[v] >= vst[u]) {
				bcc.push_back(vector<int>(0));
				while(bcc.back().push_back(st[nt]), st[nt--] ^ v);
				bcc.back().push_back(u);
			}
		}
		else if(v ^ f && vst[v] < low[u]) low[u] = vst[v];
	}
}
void init(int n) {
	bcc.clear(), E = nc = 0;
	while(vst[n] = 0, head[n] = -1, n--);
}