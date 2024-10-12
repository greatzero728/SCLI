#define pc _putchar_nolock
static char fjf[1010], so[44];
void pt(int x) {
	int n = 0; if(x < 0) pc(45), x = -x;
	while(so[n++] = x % 10, x /= 10);
	while(n--) pc(so[n] + 48);
}
char gc() {
	static char *L = fjf, *R = L;
	if(L == R) {
		int n = fread(fjf, 1, 1010, stdin);
		if(!n) return -1; L = fjf, R = L + n;
	}
	return *L++;
}
bool gn(int &x) {
	char c, t = 0; while(c = gc(), (c < 48 || 57 < c) && c ^ 45 && ~c);
	if(!~c) return 0; if(c == 45) c = gc(), t = 1;
	for(x = c - 48; c = gc(), 48 <= c && c <= 57; x = 10 * x + c - 48);
	if(t) x = -x; return 1;
}
bool gn(char &c) {while(c = gc(), ~c && isspace(c)); return ~c;}
bool gn(char *s) {
	char c; while(c = gc(), ~c && isspace(c)); if(!~c) return 0;
	for(*s++ = c; c = gc(), ~c && !isspace(c); *s++ = c); return *s = 0, 1;
}
#define gets line
bool gets(char *s) {
	char c, t = 0; while(c = gc(), ~c && c ^ 10) *s++ = c, t = 1;
	*s = 0; return ~c || t;
}
bool gn(string &s) {
	char c; while(c = gc(), ~c && isspace(c)); if(!~c) return 0;
	for(s = c; c = gc(), ~c && !isspace(c); s += c); return 1;
}
bool gn(DO &x) {
	string s; if(!gn(s)) return 0;
	x = atof(s.c_str()); return 1;
}
