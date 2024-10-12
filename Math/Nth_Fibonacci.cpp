pii Mul(pii a, pii b) {
	return {((INT)a.y * b.y + (INT)a.x * b.x) % mod, ((INT)a.y * (b.x + b.y) + (INT)a.x * b.y) % mod};
}
int calc_fibo(int n) {
	pii ans = {1, 0}, b = {0, 1};
	for(; n; n >>= 1, b = Mul(b, b)) if(n & 1) ans = Mul(ans, b);
	return ans.y;
} //get Nth_Fibonacci number.