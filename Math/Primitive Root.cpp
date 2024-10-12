int calc_root(int p) {
	int r = 3, i;
	for(bool f; f = i = 1; r++) {
		for(; f && i * i < p; i++) if((p - 1) % i < 1) {
			if(i > 1 && power(r, (p - 1) / i, p) == 1) f = 0;
			else if(power(r, i, p) == 1) f = 0;
		}
		if(f) return r;
	}
}