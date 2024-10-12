// Tree isn't change
// add(u, x) : w[u] += x
// calc(u, d) : compute sum of w[v] (Here dist(u, v) <= d)
int d[NN], w[NN], id[NN << 1], nc;
struct Bit {
	vector<int> B; int n;
	void init(int i) {B.resize(n = ++i); while(i--) B[i] = 0;}
	void add(int u, int x) {for(u++; u <= n; u += u & -u) B[u - 1] += x;}
	int calc(int u) {
		if(++u > n) u = n; int ans = 0;
		while(u > 0) ans += B[u - 1], u ^= u & -u; return ans;
	}
} t[NN << 1];

struct node {
	int rt, sb, d;
	node(int a = 0, int b = 0, int c = 0) : rt(a), sb(b), d(c) {}
};
vector<node> vec[NN];

void update(int x, int f) {
	int u, v, e;
	for(fa[q[qf = 0] = x] = f, qb = d[x] = 1; qf < qb; ) {
		vec[u].pb({id[f], id[x], d[u = q[qf++]]});
		for(e = head[u]; ~e; e = nxt[e]) {
			if(fa[u] == (v = to[e]) || vst[v]) continue;
			d[v] = d[fa[q[qb++] = v] = u] + 1;
		}
	}
}
void add(int u, int x) {
	if(!x) return; w[u] += x;
	for(node p : vec[u]) {
		t[p.rt].add(p.d, x);
		if(~p.sb) t[p.sb].add(p.d - 1, x);
	}
}
int calc(int u, int d) {
	int ans = 0;
	for(node p : vec[u]) {
		ans += t[p.rt].calc(d - p.d);
		if(~p.sb) ans -= t[p.sb].calc(d - p.d - 1);
	}
	return ans;
}
void solve(int u) {
	int v, e = head[u = cen(u)], x = 0;
	vec[u].pb({id[u] = ++nc, -1, 0});
	for(vst[u] = 1; ~e; e = nxt[e]) if(!vst[v = to[e]]) {
		id[v] = ++nc, update(v, u);
		if(x < (v = d[q[qb - 1]])) x = v;
		t[nc].init(v - 1);
	}
	t[id[u]].init(x);
	for(e = head[u]; ~e; e = nxt[e]) if(!vst[v = to[e]]) solve(v);
}
void init(int n) {
	E = nc = 0;
	do {
		vst[n] = w[n] = 0, head[n] = -1, vec[n].clear();
	}
	while(n--);
}