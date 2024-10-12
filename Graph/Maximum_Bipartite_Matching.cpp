int mr[NN], vst[NN], nc, head[NN], nxt[MM], to[MM], E;

bool bpm(int u) {
	int e = head[u], v;
	for(; ~e; e = nxt[e]) if(!~mr[v = to[e]]) return mr[v] = u, 1;
	for(e = head[u]; ~e; e = nxt[e]) if(vst[v = to[e]] ^ nc) {
		vst[v] = nc;
		if(bpm(mr[v])) return mr[v] = u, 1;
	}
	return 0;
}

void init(int n, int m) {
	E = 0;
	while(head[n] = -1, n--);
	while(mr[m] = -1, m--);
}