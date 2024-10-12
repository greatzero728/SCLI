using cp = complex<DO>;

void fft(vector<cp> &a, cp c) {
	int h, i, j, k, m = a.size(), n = m;
	for(cp w, x; m > 1; c *= c, m = h) {
		h = m >> 1, w = 1;
		for(i = 0; i < h; i++, w *= c) for(j = i; j < n; j += m)
		x = a[j] - a[k = j + h], a[j] += a[k], a[k] = w * x;
	}
	for(i = 0, j = 1; j + 1 < n; j++) {
		for(k = n >> 1; k > (i ^= k); k >>= 1);
		if(i > j) swap(a[i], a[j]);
	}
}
//len(a * b) < 1 << 23, if(a == b) f = 1
vector<int> multi(const vector<int> &a, const vector<int> &a, bool f = 0) {
	int i = a.size(), j = b.size(), m = i + j - 1;
	if(m < 256) {
		vector<int> c(m);
		while(i--) for(j = b.size(); j--; )
		c[i + j] = (c[i + j] + (INT)a[i] * b[j]) % mod;
		return c;
	}
	int n = 1 << 32 - __builtin_clz(m - 1);
	vector<int> c(n); cp w;
	vector<cp> A(n), B(n);
	while(i--) A[i] = cp(a[i], 0);
	for(i = n; j--; B[j] = cp(b[j], 0));
	
	fft(A, w = exp(cp(0, 1) * (2 * pi / n)));
	if(f) B = A;
	else fft(B, w);
	
	while(i--) A[i] *= B[i];
	fft(A, cp(w.read(0, -w.imag())));
	
	for(c.resize(m); ++i < m; ) {
		c[i] = ((INT)rint(A[i].real() / n) % mod + mod) % mod;
	}
	return c;
}