struct trie {
	static const int CC = 26;
	int nxt[NN][CC], nc, rt;
	bool flag[NN];
	
	int make() {
		flag[nc] = 0;
		int i = CC; while(i--) nxt[nc][i] = 0;
		return nc++;
	}
	void insert(char *s, int n) {
		int u = rt, c, i = -1;
		while(++i < n) {
			c = s[i] - 'a';
			if(!nxt[u][c]) nxt[u][c] = make();
			u = nxt[u][c];
		}
		flag[u] = 1;
	}
	void init() {
		nc = 0, rt = make();
	}
} tr;