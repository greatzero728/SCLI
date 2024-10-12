int gcd(int a, int b) {
	return b ? gcd(b, a % b) : a;
}
int egcd(int a, int b, int &x, int &y) {
	if(!b) return x = 1, y = 0, a;
	int g = egcd(b, a % b, y, x);
	return y -= a / b * x, g;
}