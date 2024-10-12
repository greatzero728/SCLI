int rt[NN], Ls[MM], Rs[MM], sum[MM], flag[MM], l, r, x, nc;

void push_up(int u, int L, int R) {
	int ls = Ls[u], rs = Rs[u];
	sum[u] = sum[ls] + sum[rs] + (INT)flag[u] * (R - L);
}
int build(int L, int R) {
	int u = nc++;
	if(R - L < 2) return sum[u] = 0, u;
	Ls[u] = build(L, mid), Rs[u] = build(mid, R);
	push_up(u, L, R), flag[u] = 0;
	return u;
}

int make(int u) {
	Ls[nc] = Ls[u], Rs[nc] = Rs[u];
	sum[nc] = sum[u], flag[nc] = flag[u];
	return nc++;
}
int update(int u, int L, int R) {
	int c = make(u);
	if(l <= L && R <= r) {
		sum[c] += (INT)x * (R - L), flag[c] += x;
	}
	else {
		if(l < mid) Ls[c] = update(Ls[u], L, mid);
		if(mid < r) Rs[c] = update(Rs[u], mid, R);
		push_up(c, L, R);
	}
	return c;
}
INT calc(int u, int L, int R, int up = 0) {
	if(l <= L && R <= r) return sum[u] + (INT)up * (R - L);
	INT s = l < mid ? calc(Ls[u], L, mid, up + flag[u]) : 0;
	if(mid < r) s += calc(Rs[u], mid, R, up + flag[u]);
	return s;
}

void init() {
	nc = 0;
}