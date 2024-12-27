vector<int> B[MM];
int Ls[MM], Rs[MM], mn[MM], mx[MM], A[NN], nc, x;
int build(int L, int R, int a, int b) {
	int u = nc++; mn[u] = a, mx[u] = b;
	if(L >= R || a == b) return u;
	int md = a + b >> 1; B[u].resize(R - L + 1), B[u][0] = 0;
	for(int i = L; i < R; i++) B[u][i - L + 1] = B[u][i - L] + (A[i] <= md);
	int mid = stable_partition(A + L, A + R, [&md](int x) {return x <= md;}) - A;
	return Ls[u] = build(L, mid, a, md), Rs[u] = build(mid, R, md + 1, b), u;
}
// count the val <= x, index : [L, R]
int no_big(int u, int L, int R) {
	if(L > R || x < mn[u]) return 0; if(mx[u] <= x) return R - L + 1;
	int a = B[u][L - 1], b = B[u][R];
	return no_big(Ls[u], a + 1, b) + no_big(Rs[u], L - a, R - b);
}
// count the val == x, index : [L, R]
int count(int u, int L, int R) {
	if(L > R || mx[u] < x || x < mn[u]) return 0;
	if(mn[u] == mx[u]) return R - L + 1; int a = B[u][L - 1], b = B[u][R];
	if(x > mn[u] + mx[u] >> 1) return count(Rs[u], L - a, R - b);
	return count(Ls[u], a + 1, b);
}
// kth smallest element in [L, R]
int kth(int u, int L, int R, int k) {
	if(L > R) return 0; if(mn[u] == mx[u]) return mn[u];
	int a = B[u][L - 1], b = B[u][R];
	if(k > b - a) return kth(Rs[u], L - a, R - b, k + a - b);
	return kth(Ls[u], a + 1, b, k);
}
void init(int *a, int n) {
	int i = n, mn, mx;
	for(A[i] = mn = mx = a[i]; --i; A[i] = a[i]) {
		if(a[i] < mn) mn = a[i];
		if(a[i] > mx) mx = a[i];
	}
	nc = 0, build(1, n + 1, mn, mx);
}
