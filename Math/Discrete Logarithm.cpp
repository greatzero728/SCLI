//power(x, y, mod) == k % mod => return y;
int discrete_logarithm(int x, int mod, int k) {
	if(mod == 1) return 0;
	int s = 1, b, i = 0;
	for(; i < 64; i++) {
		if(s == k) return i;
		s = (INT)s * x % mod;
	}
	for(; (b = __gcd(x, mod)) != 1; mod /= b) if(k % b) return -1;
	
	unordered_map<int, int> M;
	int q = sqrt(mod - 1) + 1;
	for(i = 0, b = 1; i < q; i++) {
		if(M.find(b) == M.end()) M[b] = i;
		b = (INT)b * x % mod;
	}
	int p = power(x, q, mod);
	for(i = 0, b = 1; i <= q; i++) {
		s = (INT)k * power(b, mod - 2, mod) % mod;
		if(M.find(s) != M.end()) {
			x = i * q + M[s];
			if(x > 63) return x;
		}
		b = (INT)b * p % mod;
	}
	return -1;
}