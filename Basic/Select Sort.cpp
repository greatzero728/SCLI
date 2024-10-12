int id[NN];
void select(int L, int md, int R, int *a) {
	int i, j, p, S, X;
	for(R--; L < R; ) {
		if(R - L < 2) {
			if(a[id[L]] > a[id[R]]) i = id[L], id[L] = id[R], id[R] = i;
			return;
		}
		S = L + 1, X = S + (rand() << 15 | rand()) % (R - L);
		i = id[L], id[L] = id[X], id[X] = i;
		if(a[id[L]] > a[id[R]]) i = id[L], id[L] = id[R], id[R] = i;
		if(a[id[L]] > a[id[S]]) i = id[L], id[L] = id[S], id[S] = i;
		if(a[id[S]] > a[id[R]]) i = id[S], id[S] = id[R], id[R] = i;
		for(i = L, j = R, p = a[id[S]]; ; ) {
			while(i <= R && a[id[i]] <= p) i++;
			while(j >= L && a[id[j]] >= p) j--;
			if(i > j) break; S = id[i], id[i] = id[j], id[j] = S;
		}
		if(md <= j) R = j;
		else if(md >= i) L = i;
		else break;
	}
}