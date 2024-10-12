const int mod = 998244353, r_ = 3, r_1 = power(r_, mod - 2, mod);

void fft(vector<int> &a, bool f) {
	int c, h, i, j, k, m, n, w, x;
	c = power(f ? r_1 : r_, (mod - 1) / (m = n = a.size()), mod);
	for(; m > 1; c = (INT)c * c % mod, m = h) {
		h = m >> 1, i = 0, w = 1;
		for(; i < h; i++, w = (INT)w * c % mod) for(j = i; j < n; j += m) {
			x = (a[j] - a[k = j + h] + mod) % mod;
			a[j] = (a[j] + a[k]) % mod, a[k] = (INT)w * x % mod;
		}
	}
	for(i = 0, j = 1; j + 1 < n; j++) {
		for(k = n >> 1; k > (i ^= k); k >>= 1);
		if(i > j) swap(a[i], a[j]);
	}
	if(f) for(x = power(n, mod - 2, mod); n--; a[n] = (INT)a[n] * x % mod);
}

//len(a * b) < 1 << 23, if(a == b) f = 1
vector<int> multi(const vector<int> &a, const vector<int> &b, bool f = 0) {
	int i = a.size(), j = b.size(), m = i + j - 1;
	if(m < 256) {
		vector<int> c(m);
		while(i--) for(j = b.size(); j--; )
		c[i + j] = (c[i + j] + (INT)a[i] * b[j]) % mod;
		return c;
	}
	int n = 1 << 32 - __builtin_clz(m - 1);
	VI A = a, B = b;
	A.resize(n), fft(A, 0);
	if(f) B = A;
	else B.resize(n), fft(B, 0);
	while(n--) A[n] = (INT)A[n] * B[n] % mod;
	fft(A, 1), A.resize(m);
	return A;
}