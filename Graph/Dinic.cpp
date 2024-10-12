struct Dinic {
	int n, s, t, d[NN], to[MM], nxt[MM];
	int E, qf, qb, q[NN], k[NN], head[NN], cap[MM];
	
	void add(int u, int v, int f) {
		cap[E] = f, to[E] = v, nxt[E] = head[u], head[u] = E++;
		cap[E] = 0, to[E] = u, nxt[E] = head[v], head[v] = E++;
	}
	
	bool bfs() {
		int u, v, e = n + (qb = 1);
		while(d[--e] = -1, e);
		for(q[qf = d[s] = 0] = s; qf < qb && !~ d[t]; )
		for(e = head[u = q[qf++]]; ~e; e = nxt[e])
		if(cap[e] && !~ d[v = to[e]]) d[q[qb++] = v] = d[u] + 1;
		return ~d[t];
	}
	
	int dfs(int u, int &b) {
		if(u == t) return b;
		for(int &e = k[u], v, c; ~e; e = nxt[e]) if(c = cap[e])
		if(d[v = to[e]] == d[u] + 1) if(v = dfs(v, c = min(b, c))) {
			cap[e] -= v, cap[e ^ 1] += v, b = c;
			return c;
		}
		return 0;
	}
	
	int flow() {
		int ans = 0, x;
		while(bfs()) {
			for(memcpy(k, head, n << 2); x = dfs(s, x = inf); ans += x);
			return ans;
		}
	}
	
	void init(int N, int S, int T) {
		n = E = N + 1, s = S, t = T;
		while(head[--E] = -1, E);
	}
} di;