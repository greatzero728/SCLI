#define CC 26

char s[NN];
int cnt[NN], ord[NN << 1], sz, ed;

struct node {
	int deep, fail, cnt, nxt[CC], val;
	void clear() {
		memset(nxt, -1, sizeof nxt);
		deep = fail = cnt = val = 0;
	}
} mem[NN << 1];

struct automation {
	void init() {
		for(int i = CC; i--; ) mem[0].nxt[i] = 1;
		mem[0].deep = -1;
		mem[1].clear(), mem[1].cnt = 1;
		sz = 2, ed = 1;
	}
	void insert(int c) {
		int p = sz++;
		mem[p].clear();
		mem[p].deep = mem[ed].deep + 1;
		mem[p].val = 1;
		while(mem[ed].nxt[c] == -1) {
			mem[ed].nxt[c] = p;
			mem[p].cnt += mem[ed].cnt;
			ed = mem[ed].fail;
		}
		int p1 = mem[ed].nxt[c];
		if(mem[p1].deep == mem[ed].deep + 1) mem[p].fail = p1;
		else {
			int p2 = sz++;
			mem[p2] = mem[p1];
			mem[p2].deep = mem[ed].deep + 1;
			mem[p2].cnt = 0;
			mem[p2].val = 0;
			
			mem[p].fail = mem[p1].fail = p2;
			while(mem[p2].nxt[c] == p1) {
				mem[ed].nxt[c] = p2;
				mem[p1].cnt -= mem[ed].cnt;
				mem[p2].cnt += mem[ed].cnt;
				ed = mem[ed].fail;
			}
		}
		ed = p;
	}
	void build(int n) {
		int i = 1, cur, prv;
		memset(cnt, 0, sizeof cnt);
		for(; i < sz; i++) cnt[mem[i].deep]++;
		for(i = 1; i < NN; i++) cnt[i] += cnt[i - 1];
		for(i = 1; i < sz; i++) ord[--cnt[mem[i].deep]] = i;
		for(i = sz - 1; i--; ) {
			cur = ord[i], prv = mem[cur].fail;
			mem[prv].val += mem[cur].val;
		}
	}
} sam;