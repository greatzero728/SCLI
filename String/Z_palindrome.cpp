//Manacher's Algorithm
//Only odd palindrome length is considered.
//z[i] means that the longest odd palindrome centered at i is [i - z[i] ... i + z[i]]
int z[NN];

void zpal(char *s, int n) {
	int i = 0, b = z[0] = 0;
	while(++i < n) {
		z[i] = b + z[b] < i ? 0 : min(z[b + b - i], b + z[b] - i);
		while(i + z[i] + 1 < n && i > z[i] && s[i + z[i] + 1] == s[i - z[i] - 1]) z[i]++;
		if(z[i] + i > z[b] + b) b = i;
	}
}