int fail[NN]; //0-index
void build_fail(char *s, int n) {
	for(int i = 0, b = fail[0] = -1; ++i < n; fail[i] = b) {
		while(~b && s[b + 1] ^ s[i]) b = fail[b];
		if(s[b + 1] == s[i]) b++;
	}
}
void match(char *t, int m, char *s, int n) {
	for(int i = 0, b = -1; i < n; i++) {
		while(~b && t[b + 1] ^ s[i]) b = fail[b];
		if(t[b + 1] == s[i]) b++;
		if(b == m - 1) {
			//s[i - m + 1, i] is same as t
			b = fail[b];
		}
	}
}

int fail[NN]; //1-index
void build_fail(char *s, int n) {
	for(int i = 1, b = fail[1] = 0; i++ < n; fail[i] = b) {
		while(b && s[b + 1] ^ s[i]) b = fail[b];
		if(s[b + 1] == s[i]) b++;
	}
}
void match(char *t, int m, char *s, int n) {
	for(int i = 0, b = 0; i++ < n; ) {
		while(b && t[b + 1] ^ s[i]) b = fail[b];
		if(t[b + 1] == s[i]) b++;
		if(b == m) {
			//s[i - m + 1, i] is same as t
			b = fail[b];
		}
	}
}