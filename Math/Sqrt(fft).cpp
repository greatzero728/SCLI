const int p_ = power(2, mod - 2, mod);

vector<int> square_root(const vector<int> &f) {
	vector<int> a, b(1, 1), c = f;
	int i, n = f.size(), m = 1 << 32 - __builtin_clz(n - 1), t = 2;
	for(c.resize(m); t <= m; t <<= 1, b = a) {
		b.resize(t);
		a = multi(invert(b), vector<int>(c.begin(), c.begin() + t));
		a.resize(t), i = b.size();
		while(i--) a[i] = (a[i] + b[i]) % mod;
		while(++i < a.size()) a[i] = (INT)a[i] * p_ % mod;
	}
	return b.resize(n), b;
}