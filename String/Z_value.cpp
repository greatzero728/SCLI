int z[NN]; //0-index
void zval(char *s, int n) {
	int i = 0, b = z[0] = 0;
	while(++i < n) {
		z[i] = max(min(b + z[b] - i, z[i - b]), 0);
		while(s[i + z[i]] == s[z[i]]) z[i]++;
		if(i + z[i] > b + z[b]) b = i;
	}
	z[0] = n;
}

int z[NN]; //1-index
void zval(char *s, int n) {
	int i = 1, b = 1; z[1] = 0;
	while(i++ < n) {
		z[i] = max(min(b + z[b] - i, z[i - b + 1]), 0);
		while(s[i + z[i]] == s[z[i] + 1]) z[i]++;
		if(i + z[i] > b + z[b]) b = i;
	}
	z[1] = n;
}