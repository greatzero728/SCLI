bool check(const vector<int> &a, const vector<int> &b) {
	for(int i = a.size(), j, x; i--; ) {
		j = x = 0;
		while(j <= i) x = ((INT)a[i - j] * b[j] + x) % mod, j++;
		if(x ^ !i) return 0;
	}
	return 1;
} //return a * b == I

vector<int> invert(const vector<int> &f) {
	vector<int> a, b(1, power(f[0], mod - 2, mod)), c = f;
	int i, n = f.size(), m = 1 << 32 - __builtin_clz(n - 1), t = 2;
	for(c.resize(m); t <= m; t <<= 1, b = a) {
		a = multi(multi(b, b, 1), vector<int>(c.begin(), c.begin() + t));
		a.resize(i = t);
		while(i--) if(a[i]) a[i] = mod - a[i];
		i = t >> 1;
		while(i--) a[i] = (2LL * b[i] + a[i]) % mod;
	}
	if(b.size() > n) b.resize(n);
	return b;
}