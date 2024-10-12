// 0-based
const int _mx = 20; // 1 << _mx > n

ppi pos[NN];
int H[NN], Rank[NN], sa[NN];

//int head[NN], nxt[NN];
//ppi buf[NN], tbuf[NN];
//
//void b_sort(int n, bool f) {
//	int e = 0, N = 0, ed = max(n + 2, 130), i = ed, u, deg;
//	while(i--) head[i] = -1;
//	while(++i < n) {
//		u = (f ? pos[i].x.x : pos[i].x.y) + 1;
//		buf[e] = pos[i], nxt[e] = head[u], head[u] = e++;
//	}
//	for(u = 0; u < ed; u++) {
//		for(deg = 0, e = head[u]; ~e; e = nxt[e]) tbuf[deg++] = buf[e];
//		while(deg) pos[N++] = tbuf[--deg];
//	}
//}

void build_suf(char *s, int n) {
	int i, j = n, cnt, u;
	while(j--) Rank[j] = s[j]; pos[n] = {{-1, -1}, -1};
	Rank[n] = -inf;
//	Rank[n] = 0;
	while(++j < _mx) {
		i = n, cnt = 0;
		while(i--) pos[i] = {{Rank[i], Rank[min(n, i + (1 << j))]}, i};
		sort(pos, pos + n);
//		b_sort(n, 0), b_sort(n, 1);
		while(++i < n) {
			Rank[pos[i].y] = cnt + 1;
			if(pos[i].x != pos[i + 1].x) cnt++;
		}
		if(cnt == n) break;
	}
	while(i--) sa[Rank[i]] = i;
}
void Height(char *s, int n) {
	for(int i = 0, j, h = 0; i < n; i++) if(Rank[i] > 1) {
		h = max(0, h - 1), j = sa[Rank[i] - 1];
		while(i + h < n && j + h < n && s[i + h] == s[j + h]) h++;
		H[Rank[i]] = h;
	}
}

int mn[NN][_mx];
void rmq(int n) {
	int i = 0, j = 0;
	while(i++ < n) mn[i][0] = H[i];
	while(++j < _mx) for(i = 0; i++ < n; ) {
		mn[i][j] = min(mn[i][j - 1], mn[min(n, i + (1 << j - 1))][j - 1]);
	}
}
int calc_min(int L, int R) {
	int k = 31 - __builtin_clz(R - L + 1);
	return min(mn[L][k], mn[R - (1 << k) + 1][k]);
}