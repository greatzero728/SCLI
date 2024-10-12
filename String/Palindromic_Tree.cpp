struct p_tree {
	static const int CC = 26;
	int nxt[NN][CC], fail[NN], len[NN], s[NN], sz, ed, n;
	void clear(int u, int L) {
		fail[u] = 0, len[u] = L, L = CC;
		while(L--) nxt[u][L] = 0;
	}
	int get_fail(int u) {
		while(s[n - len[u] - 1] ^ s[n]) u = fail[u];
		return u;
	}
	void insert(int c) {
		s[++n] = c, ed = get_fail(ed);
		if(!nxt[ed][c]) {
			int u = sz++, v = get_fail(fail[ed]);
			clear(u, len[ed] + 2);
			fail[u] = nxt[v][c], nxt[ed][c] = u;
		}
		ed = nxt[ed][c];
	}
	void init() {
		s[n = 0] = -1, sz = 2;
		clear(0, 0), clear(fail[0] = ed = 1, -1);
	}
} pt;