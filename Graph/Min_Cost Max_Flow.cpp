struct mcmf {
	PQ q;
	int d[NN], pv[NN], pe[NN], nxt[MM], to[MM];
	int V, E, k[NN], head[NN], cap[MM], cost[MM];
	
	void add(int u, int v, int f, int c) {
		cap[E] = f, cost[E] = c, to[E] = v, nxt[E] = head[u], head[u] = E++;
		cap[E] = 0, cost[E] = -c, to[E] = u, nxt[E] = head[v], head[v] = E++;
	}
	pii minCost(int s, int t, int x) { //max_flow <= x
		int u, e, g, i = V, f = 0, c = 0;
		while(k[i] = 0, i--);
		while(x) {
			q = PQ(), i = V;
			while(d[i] = inf, i--);
			q.push({d[s] = 0, s});
			while(!q.empty()) {
				g = q.top().x, u = q.top().y, q.pop();
				if(d[u] >= g) for(e = head[u]; ~e; e = nxt[e]) if(cap[e]) {
					g = d[u] + cost[e] + k[u] - k[i = to[e]];
					if(d[i] > g) pv[i] = u, pe[i] = e, q.push({d[i] = g, i});
				}
			}
			if(d[u = t] == inf) break;
			i = V, g = x;
			while(k[i] += d[i], i--);
			for(; u ^ s; u = pv[u]) if(cap[pe[u]] < g) g = cap[pe[u]];
			x -= g, f += g, c += g * k[u = t];
			while(u ^ s) cap[pe[u]] -= g, cap[pe[u] ^ 1] += g, u = pv[u];
		}
		return {f, c};
	}
	void init(int n) {
		V = E = n + 1;
		while(head[--E] = -1, E);
	}
} mc;