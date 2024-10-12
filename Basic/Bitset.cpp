struct Bitset {
	unsigned long long b[6252];
	int len = 6252; // sz = NN / 64 + 7
	Bitset() {}
	Bitset(int n) {len = n + 63 >> 6, reset();}
	void set() {for(int i = len; i--; ) b[i] = -1;}
	void set(int i) {b[i >> 6] |= 1ULL << (i & 63);}
	void reset() {for(int i = len; i--; ) b[i] = 0;}
	void reset(int i) {b[i >> 6] &= ~(1ULL << (i & 63));}
	void flip() {for(int i = len; i--; ) b[i] = ~b[i];}
	void flip(int i) {b[i >> 6] ^= 1ULL << (i & 63);}
	bool operator[] (int i) {return b[i >> 6] >> (i & 63) & 1;}
	bool any() {
		for(int i = len; i--; ) if(b[i]) return 1;
		return 0;
	}
	int count() {
		int ans = 0, i = len;
		while(i--) ans += __builtin_popcountll(b[i]);
		return ans;
	}
	Bitset operator | (Bitset a) {
		Bitset ans; ans.len = len;
		for(int i = len; i--; ) ans.b[i] = b[i] | a.b[i];
		return ans;
	}
	Bitset operator & (Bitset a) {
		Bitset ans; ans.len = len;
		for(int i = len; i--; ) ans.b[i] = b[i] & a.b[i];
		return ans;
	}
	Bitset operator ^ (Bitset a) {
		Bitset ans; ans.len = len;
		for(int i = len; i--; ) ans.b[i] = b[i] ^ a.b[i];
	}
	Bitset operator ~ () {
		Bitset ans; ans.len = len;
		for(int i = len; i--; ) ans.b[i] = ~b[i];
		return ans;
	}
	Bitset operator << (int k) {
		Bitset ans; ans.len = len;
		int m = k >> 6, r = k & 63, i = 0;
		while(i < m) ans.b[i++] = 0;
		ans.b[m] = b[0] << r;
		while(++i < len) {
			ans.b[i] = b[i - m] << r;
			if(r) ans.b[i] |= b[i - m - 1] >> 64 - r;
		}
		return ans;
	}
	Bitset operator >> (int k) {
		Bitset ans; ans.len = len;
		int m = k >> 6, r = k & 63, i = len;
		while(i-- > len - m) ans.b[i] = 0;
		ans.b[len - m - 1] = b[len - 1] >> r;
		while(i--) {
			ans.b[i] = b[i + m] >> r;
			if(r) ans.b[i] |= b[i + m + 1] << 64 - r;
		}
		return ans;
	}
	int front() {
		int i = -1;
		while(++i < len) if(b[i]) return 64 * i + __builtin_ctzll(b[i]);
		return len << 6;
	}
};