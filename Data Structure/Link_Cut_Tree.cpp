bool rev[NN];
int son[NN][2], pa[NN], lt[NN], nc;
//int vir[NN], sz[NN];

void push_down(int u) {
	int &ls = son[u][0], &rs = son[u][1];
	if(rev[u]) rev[ls] ^= 1, rev[rs] ^= 1, swap(ls, rs), rev[u] = 0;
}
void push_up(int u) {
	int ls = son[u][0], rs = son[u][1];
//	sz[u] = sz[ls] + sz[rs] + vir[u] + 1;
	
}

bool is_root(int u) {
	return son[pa[u]][0] ^ u && son[pa[u]][1] ^ u;
}
void down(int u) {
	while(!is_root(lt[++nc] = u)) u = pa[u];
	while(nc) push_down(lt[nc--]);
}
void rot(int x, bool d) {
	int y = pa[x], z = pa[y];
	if(son[z][0] == y) son[z][0] = x;
	else if(son[z][1] == y) son[z][1] = x;
	pa[x] = pa[pa[son[y][!d] = son[x][d]] = y], push_down(son[pa[y] = x][d] = y);
}
void splay(int x) {
	down(x);
	bool d;
	for(int y; !is_root(x); rot(x, d))
	if(is_root(y = pa[x])) d = son[y][0] == x;
	else son[y][d = son[pa[y]][0] == y] == x ? rot(x, !d) : rot(y, d);
	push_up(x);
}
void access(int x) {
	for(int y = 0; x; x = pa[y = x]) {
		splay(x);
//		vir[x] += sz[son[x][1]] - sz[y];
		son[x][1] = y, push_up(x);
	}
}
void make_root(int u) {
	access(u), splay(u), rev[u] ^= 1;
}
void get(int u, int v) {
	make_root(u), access(v);
}
int get_root(int u) {
	access(u), splay(u);
	while(son[u][0]) u = son[u][0];
	return u;
}
bool is_linked(int f, int u) {
	get(f, u), splay(f);
	while(!is_root(u)) u = pa[u];
	return f == u;
}
bool is_up(int f, int u) {
	if(!u) return 0;
	access(u), splay(u);
	while(!is_root(f)) f = pa[f];
	return f == u;
}
void link(int u, int f) {
	make_root(u);
//	access(f), splay(f), vir[f] += sz[u];
	pa[u] = f;
}
void cut(int f, int u) {
	make_root(f);
//	access(u);
	splay(u), pa[son[u][0]] = pa[u], pa[u] = son[u][0] = 0;
}
void init(int n) {
	while(n) {
//		vir[n] = 0, sz[n] = 1;
		son[n][0] = son[n][1] = rev[n] = pa[n] = 0, n--;
	}
}