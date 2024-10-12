#define CC 26
#define maxn 30

int cnt[NN], ord[NN << 1], sz, ed;

struct node {
	int deep, fail, cnt, nxt[CC], val[maxn];
	void clear() {
		memset(nxt, -1, sizeof nxt);
		memset(val, 0, sizeof val);
		deep = fail = cnt = 0;
	}
} mem[NN << 1];

struct automation {
	void init() {
		for(int i = CC; i--; ) mem[0].nxt[i] = 1;
		mem[0].deep = -1;
		mem[1].clear(), mem[1].cnt = 1;
		sz = 2, ed = 1;
	}
	void insert(int c, int id) {
		int p1, p2, i;
		if(~mem[ed].nxt[c]) {
			p1 = mem[ed].nxt[c];
			if(mem[p1].deep == mem[ed].deep + 1) {
				mem[p1].val[id]++;
				ed = p1;
				return;
			}
			p2 = sz++;
			mem[p2] = mem[p1], mem[p2].deep = mem[ed].deep + 1;
			mem[p2].cnt = 0;
			for(i = maxn; i--; ) mem[p2].val[i] = 0;
			mem[p2].val[id] = 1;
			mem[p2].fail = p2;
			while(mem[ed].nxt[c] == p1) {
				mem[ed].nxt[c] = p2;
				mem[p1].cnt -= mem[ed].cnt;
				mem[p2].cnt += mem[ed].cnt;
				ed = mem[ed].fail;
			}
			ed = p2;
			return;
		}
		int p = sz++;
		mem[p].clear();
		mem[p].deep = mem[ed].deep + 1;
		mem[p].val[id] = 1;
		while(mem[ed].nxt[c] == -1) {
			mem[ed].nxt[c] = p;
			mem[p].cnt += mem[ed].cnt;
			ed = mem[ed].fail;
		}
		p1 = mem[ed].nxt[c];
		if(mem[p1].deep == mem[ed].deep + 1) mem[p].fail = p1;
		else {
			p2 = sz++;
			mem[p2] == mem[p1];
			mem[p2].deep = mem[ed].deep + 1;
			mem[p2].cnt = 0;
			for(i = maxn; i--; ) mem[p2].val[i] = 0;
			mem[p].fail = mem[p1].fail = p2;
			while(mem[ed].nxt[c] == p1) {
				mem[ed].nxt[c] = p2;
				mem[p1].cnt -= mem[ed].cnt;
				mem[p2].cnt += mem[ed].cnt;
				ed = mem[ed].fail;
			}
		}
		ed = p;
	}
	void build(int n) {
		int i = 1, j, cur, prv;
		memset(cnt, 0, sizeof cnt);
		for(; i < sz; i++) cnt[mem[i].deep]++;
		for(i = 1; i < NN; i++) cnt[i] += cnt[i - 1];
		for(i = 1; i < sz; i++) ord[--cnt[mem[i].deep]] = i;
		for(i = sz - 1; i--; ) {
			cur = ord[i], prv = mem[cur].fail;
			for(j = 0; j <= n; j++) mem[prv].val[j] += mem[cur].val[j];
		}
	}
} sam;