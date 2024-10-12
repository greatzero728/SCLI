int Ls[MM], xmn[MM], ymn[MM], x[NN], y[NN];
int Rs[MM], xmx[MM], ymx[MM], id[NN], nc;

int build(int L, int R, bool f = 0) {
	int u = nc++;
	if(R - L < 2) {
		xmn[u] = xmx[u] = x[id[L]], ymn[u] = ymx[u] = y[id[L]];
		return u;
	}
	if(f) nth_element(id + L, id + mid, id + R, [&](int u, int v) {return x[u] < x[v];});
	else nth_element(id + L, id + mid, id + R, [&](int u, int v) {return y[u] < y[v];});
	
	int ls = Ls[u] = build(L, mid, f ^ 1), rs = Rs[u] = build(mid, R, f ^ 1);
	xmn[u] = min(xmn[ls], xmn[rs]), xmx[u] = max(xmx[ls], xmx[rs]);
	ymn[u] = min(ymn[ls], ymn[rs]), ymx[u] = max(ymx[ls], ymx[rs]);
	return u;
}

void init() {
	nc = 0;
}