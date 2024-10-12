int pa[NN], son[NN][2], sz[NN], val[NN], nc, rt;
int make(int x) {
	sz[++nc] = 1, val[nc] = x;
	pa[nc] = son[nc][0] = son[nc][1] = 0;
	return nc;
}
void push_down(int u) {
	int &ls = son[u][0], &rs = son[u][1];
	
}
void push_up(int u) {
	int ls = son[u][0], rs = son[u][1];
	sz[u] = 1;
	if(ls) {
		sz[u] += sz[ls];
	}
	if(rs) {
		sz[u] += sz[rs];
	}
}
void rot(int x, bool d) {
	int y = pa[x], z = pa[y];
	if(son[z][0] == y) son[z][0] = x;
	else if(son[z][1] == y) son[z][1] = x;
	pa[x] = pa[pa[son[y][!d] = son[x][d]] = y];
	push_up(son[pa[y] = x][d] = y);
}
void splay(int x, int g) {
	bool d;
	for(int y; pa[x] ^ g; rot(x, d))
	if(pa[y = pa[x]] == g) d = son[y][0] == x;
	else son[y][d = son[pa[y]][0] == y] == x ? rot(x, !d) : rot(y, d);
	push_up(x);
	if(!g) rt = x;
}
void print(int u) {
	if(!u) return;
	push_down(u), print(son[u][0]);
	cerr<<val[u]<<' ', print(son[u][1]);
}
int find(int u, int k) {
	int s;
	while(1) {
		push_down(u);
		if(k <= sz[s = son[u][0]]) {u = s; continue;}
		if(!(k -= sz[s] + 1)) return u;
		u = son[u][1];
	}
}
void insert(int k, int c) {
	int x = find(rt, k);
	splay(x, 0), splay(k = find(x, k + 1), x);
	push_up(pa[son[k][0] = make(c)] = k), push_up(x);
}
void init() {
	make(nc = 0), make(0);
	sz[rt = pa[2] = 1] = son[1][1] = 2;
}