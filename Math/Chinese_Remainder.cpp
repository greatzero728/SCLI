int multi(int x, int y, int m) {
	return ((INT)x * y % m + m) % m;
}
INT multi(INT x, INT y, INT m) {
	return (x * y - (INT)(x / (long double)m * y + 1e-7) * m + m) % m;
}
int gcd(int a, int b, int &x, int &y) {
	if(!b) return x = 1, y = 0, a;
	int g = egcd(b, a % b, y, x);
	return y -= a / b * x, g;
}

//x % p[i] = a[i] (i = 0 ... n - 1) ==>> ans = x % lcm(p[i])
//When gcd(p[i], p[j]) = 1 (i < j), then sz(ans) = 1
//If ans == -1, no solution
struct ch_rm {
	static const int CC = 13;
	int a[CC], p[CC];
	bool can(int &s, int &a, int t, int b) {
		int x, g;
		if((s - t) % (g = egcd(a, b, x, g))) return 0;
		s += a * multi(x, (t - s) / g, b /= g);
		return a *= b, 1;
	}
	int calc(int n) {
		int x = 0, m = 1, i = n;
		while(i--) if(!can(x, m, a[i], p[j])) return -1;
		return x;
	}
} ch;