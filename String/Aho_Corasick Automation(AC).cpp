#define CC 26
int q[NN], qf, qb, used;

struct node {
	int nxt[CC], fail, cnt;
	void clear() {
		fail = -1, cnt = 0;
		memset(nxt, -1, sizeof nxt);
	}
} mem[NN];

struct AC {
	int newnode() {
		mem[++used].clear();
		return used;
	}
	void init() {used = -1, qf = qb = 0, newnode();}
	void insert(char *s) {
		int now = 0, i = 0, c;
		for(; s[i]; i++) {
			c = s[i] - 'a';
			if(mem[now].nxt[c] == -1) mem[now].nxt[c] = newnode();
			now = mem[now].nxt[c];
		}
		mem[now].cnt++;
	}
	
//	mem[u].nxt[c] can be 0, 1, 2, 3, ... and speed of this process is more faster
//	After this process :: mem[u].nxt[c] -->> find_nxt(u, c);
	void build() {
		mem[0].fail = 0;
		int u, i = CC;
		while(i--) {
			if(~mem[0].nxt[i]) {
				mem[mem[0].nxt[i]].fail = 0;
				q[qb++] = mem[0].nxt[i];
			}
			else mem[0].nxt[i] = 0;
		}
		while(qf < qb) {
			u = q[qf++];
			mem[u].cnt += mem[mem[u].fail].cnt;
			for(i = CC; i--; ) {
				if(~mem[u].nxt[i]) {
					mem[mem[u].nxt[i]].fail = mem[mem[u].fail].nxt[i];
					q[qb++] = mem[u].nxt[i];
				}
				else mem[u].nxt[i] = mem[mem[u].fail].nxt[i];
			}
		}
	}
	
	int find_nxt(int p, int c) {
		while(~p && mem[p].nxt[c] == -1) p = mem[p].fail;
		return ~p ? mem[p].nxt[c] : 0;
	}
	
//	mem[u].nxt[c] can be -1, 1, 2, 3, ... and speed of this process is slow.
	void build_fail() {
		int u, nx, now, i;
		qf = qb = 0, q[qb++] = 0;
		while(qf < qb) {
			u = q[qf++];
			if(~mem[u].fail) mem[u].cnt += mem[mem[u].fail].cnt;
			for(i = CC; i--; ) {
				nx = mem[u].nxt[i];
				if(~nx) {
					now = mem[u].fail;
					while(~now && mem[now].nxt[i] == -1) now = mem[now].fail;
					mem[nx].fail = ~now ? mem[now].nxt[i] : 0;
					q[qb++] = nx;
				}
			}
		}
	}
} ac;